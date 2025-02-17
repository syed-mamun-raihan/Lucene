#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>

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
 * Additional methods from Java 9's <a
 * href="https://docs.oracle.com/javase/9/docs/api/java/util/Objects.html">
 * {@code java.util.Objects}</a>.
 * <p>
 * This class will be removed when Java 9 is minimum requirement.
 * Currently any bytecode is patched to use the Java 9 native
 * classes through MR-JAR (Multi-Release JAR) mechanism.
 * In Java 8 it will use THIS implementation.
 * Because of patching, inside the Java source files we always
 * refer to the Lucene implementations, but the final Lucene
 * JAR files will use the native Java 9 class names when executed
 * with Java 9.
 * @lucene.internal
 */
class FutureObjects final : public std::enable_shared_from_this<FutureObjects>
{
  GET_CLASS_NAME(FutureObjects)

private:
  FutureObjects();

  /**
   * Behaves like Java 9's Objects.checkIndex
   * @see <a
   * href="http://download.java.net/java/jdk9/docs/api/java/util/Objects.html#checkIndex-int-int-">Objects.checkIndex</a>
   */
public:
  static int checkIndex(int index, int length);

  /**
   * Behaves like Java 9's Objects.checkFromToIndex
   * @see <a
   * href="http://download.java.net/java/jdk9/docs/api/java/util/Objects.html#checkFromToIndex-int-int-int-">Objects.checkFromToIndex</a>
   */
  static int checkFromToIndex(int fromIndex, int toIndex, int length);

  /**
   * Behaves like Java 9's Objects.checkFromIndexSize
   * @see <a
   * href="http://download.java.net/java/jdk9/docs/api/java/util/Objects.html#checkFromIndexSize-int-int-int-">Objects.checkFromIndexSize</a>
   */
  static int checkFromIndexSize(int fromIndex, int size, int length);
};

} // #include  "core/src/java/org/apache/lucene/util/
