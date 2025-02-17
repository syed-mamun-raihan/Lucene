#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <unordered_set>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/util/RecyclingByteBlockAllocator.h"

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
namespace org::apache::lucene::util
{

/**
 * Testcase for {@link RecyclingByteBlockAllocator}
 */
class TestRecyclingByteBlockAllocator : public LuceneTestCase
{
  GET_CLASS_NAME(TestRecyclingByteBlockAllocator)

  /**
   */
public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Override @Before public void setUp() throws Exception
  void setUp()  override;

private:
  std::shared_ptr<RecyclingByteBlockAllocator> newAllocator();

public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testAllocate()
  virtual void testAllocate();

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testAllocateAndRecycle()
  virtual void testAllocateAndRecycle();

  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Test public void testAllocateAndFree()
  virtual void testAllocateAndFree();

protected:
  std::shared_ptr<TestRecyclingByteBlockAllocator> shared_from_this()
  {
    return std::static_pointer_cast<TestRecyclingByteBlockAllocator>(
        LuceneTestCase::shared_from_this());
  }
};
} // #include  "core/src/java/org/apache/lucene/util/
