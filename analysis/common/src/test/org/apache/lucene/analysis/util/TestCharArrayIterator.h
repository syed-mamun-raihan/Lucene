#pragma once
#include "../../../../../../../../../test-framework/src/java/org/apache/lucene/util/LuceneTestCase.h"
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/util/CharArrayIterator.h"

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
namespace org::apache::lucene::analysis::util
{

using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;

class TestCharArrayIterator : public LuceneTestCase
{
  GET_CLASS_NAME(TestCharArrayIterator)

public:
  virtual void testWordInstance();

  virtual void testConsumeWordInstance();

  /* run this to test if your JRE is buggy
  public void testWordInstanceJREBUG() {
    // we use the default locale, as it's randomized by LuceneTestCase
    BreakIterator bi = BreakIterator.getWordInstance(Locale.getDefault());
    Segment ci = new Segment();
    for (int i = 0; i < 10000; i++) {
      char text[] = _TestUtil.randomUnicodeString(random).toCharArray();
      ci.array = text;
      ci.offset = 0;
      ci.count = text.length;
      consume(bi, ci);
    }
  }
  */

  virtual void testSentenceInstance();

  virtual void testConsumeSentenceInstance();

  /* run this to test if your JRE is buggy
  public void testSentenceInstanceJREBUG() {
    // we use the default locale, as it's randomized by LuceneTestCase
    BreakIterator bi = BreakIterator.getSentenceInstance(Locale.getDefault());
    Segment ci = new Segment();
    for (int i = 0; i < 10000; i++) {
      char text[] = _TestUtil.randomUnicodeString(random).toCharArray();
      ci.array = text;
      ci.offset = 0;
      ci.count = text.length;
      consume(bi, ci);
    }
  }
  */

private:
  void doTests(std::shared_ptr<CharArrayIterator> ci);

  void consume(std::shared_ptr<BreakIterator> bi,
               std::shared_ptr<CharacterIterator> ci);

protected:
  std::shared_ptr<TestCharArrayIterator> shared_from_this()
  {
    return std::static_pointer_cast<TestCharArrayIterator>(
        org.apache.lucene.util.LuceneTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/util/
