#pragma once
#include "stringhelper.h"
#include <limits>
#include <memory>
#include <stdexcept>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/util/automaton/Automaton.h"

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
namespace org::apache::lucene::util::automaton
{

using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;

// C++ TODO: The Java 'import static' statement cannot be converted to C++:
//    import static
//    org.apache.lucene.util.automaton.Operations.DEFAULT_MAX_DETERMINIZED_STATES;

/**
 * Not completely thorough, but tries to test determinism correctness
 * somewhat randomly.
 */
class TestDeterminism : public LuceneTestCase
{
  GET_CLASS_NAME(TestDeterminism)

  /** test a bunch of random regular expressions */
public:
  virtual void testRegexps() ;

  /** test against a simple, unoptimized det */
  virtual void testAgainstSimple() ;

private:
  static void assertAutomaton(std::shared_ptr<Automaton> a);

protected:
  std::shared_ptr<TestDeterminism> shared_from_this()
  {
    return std::static_pointer_cast<TestDeterminism>(
        org.apache.lucene.util.LuceneTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/util/automaton/
