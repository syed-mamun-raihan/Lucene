#pragma once
#include "exceptionhelper.h"
#include "stringhelper.h"
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/store/LockFactory.h"

#include  "core/src/java/org/apache/lucene/store/IndexInput.h"
#include  "core/src/java/org/apache/lucene/store/IOContext.h"

/*
 * Licensed to the Syed Mamun Raihan (sraihan.com) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * sraihan.com licenses this file to You under GPLv3 License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
namespace org::apache::lucene::store
{

/** A straightforward implementation of {@link FSDirectory}
 *  using java.io.RandomAccessFile.  However, this class has
 *  poor concurrent performance (multiple threads will
 *  bottleneck) as it synchronizes when multiple threads
 *  read from the same file.  It's usually better to use
 *  {@link NIOFSDirectory} or {@link MMapDirectory} instead.
 *  <p>
 *  NOTE: Because this uses RandomAccessFile, it will generally
 *  not work with non-default filesystem providers. It is only
 *  provided for applications that relied on the fact that
 *  RandomAccessFile's IO was not interruptible.
 */
// C++ TODO: Most Java annotations will not have direct C++ equivalents:
// ORIGINAL LINE: @SuppressForbidden(reason = "java.io.File: RAFDirectory is
// legacy API") public class RAFDirectory extends FSDirectory
class RAFDirectory : public FSDirectory
{

  /** Create a new RAFDirectory for the named location.
   *  The directory is created at the named location if it does not yet exist.
   *
   * @param path the path of the directory
   * @param lockFactory the lock factory to use
   * @throws IOException if there is a low-level I/O error
   */
public:
  RAFDirectory(std::shared_ptr<Path> path,
               std::shared_ptr<LockFactory> lockFactory) ;

  /** Create a new SimpleFSDirectory for the named location and {@link
   * FSLockFactory#getDefault()}. The directory is created at the named location
   * if it does not yet exist.
   *
   * @param path the path of the directory
   * @throws IOException if there is a low-level I/O error
   */
  RAFDirectory(std::shared_ptr<Path> path) ;

  /** Creates an IndexInput for the file with the given name. */
  std::shared_ptr<IndexInput>
  openInput(const std::wstring &name,
            std::shared_ptr<IOContext> context)  override;

  /**
   * Reads bytes with {@link RandomAccessFile#seek(long)} followed by
   * {@link RandomAccessFile#read(byte[], int, int)}.
   */
public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @SuppressForbidden(reason = "java.io.File: RAFDirectory is
  // legacy API") static final class RAFIndexInput extends BufferedIndexInput
  class RAFIndexInput final : public BufferedIndexInput
  {
    /**
     * The maximum chunk size is 8192 bytes, because {@link RandomAccessFile}
     * mallocs a native buffer outside of stack if the read buffer size is
     * larger.
     */
  private:
    static constexpr int CHUNK_SIZE = 8192;

    /** the file channel we will read from */
  protected:
    const std::shared_ptr<RandomAccessFile> file;
    /** is this instance a clone and hence does not own the file to close it */
  public:
    bool isClone = false;
    /** start offset: non-zero in the slice case */
  protected:
    const int64_t off;
    /** end offset (start+length) */
    const int64_t end;

  public:
    RAFIndexInput(const std::wstring &resourceDesc,
                  std::shared_ptr<RandomAccessFile> file,
                  std::shared_ptr<IOContext> context) ;

    RAFIndexInput(const std::wstring &resourceDesc,
                  std::shared_ptr<RandomAccessFile> file, int64_t off,
                  int64_t length, int bufferSize);

    virtual ~RAFIndexInput();

    std::shared_ptr<RAFIndexInput> clone() override;

    std::shared_ptr<IndexInput>
    slice(const std::wstring &sliceDescription, int64_t offset,
          int64_t length)  override;

    int64_t length() override final;

    /** IndexInput methods */
  protected:
    void readInternal(std::deque<char> &b, int offset,
                      int len)  override;

    void seekInternal(int64_t pos)  override;

  public:
    bool isFDValid() ;

  protected:
    std::shared_ptr<RAFIndexInput> shared_from_this()
    {
      return std::static_pointer_cast<RAFIndexInput>(
          BufferedIndexInput::shared_from_this());
    }
  };

protected:
  std::shared_ptr<RAFDirectory> shared_from_this()
  {
    return std::static_pointer_cast<RAFDirectory>(
        FSDirectory::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/store/
