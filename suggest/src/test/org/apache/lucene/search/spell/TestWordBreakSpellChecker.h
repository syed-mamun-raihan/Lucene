#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/store/Directory.h"

#include  "core/src/java/org/apache/lucene/analysis/Analyzer.h"

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
namespace org::apache::lucene::search::spell
{

using Analyzer = org::apache::lucene::analysis::Analyzer;
using Directory = org::apache::lucene::store::Directory;
using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;

class TestWordBreakSpellChecker : public LuceneTestCase
{
  GET_CLASS_NAME(TestWordBreakSpellChecker)
private:
  std::shared_ptr<Directory> dir;
  std::shared_ptr<Analyzer> analyzer;

public:
  void setUp()  override;

  void tearDown()  override;

  virtual void testCombiningWords() ;

  virtual void testBreakingWords() ;

  virtual void testRandom() ;

private:
  static const std::shared_ptr<Pattern> mockTokenizerWhitespacePattern;

  bool goodTestString(const std::wstring &s);

protected:
  std::shared_ptr<TestWordBreakSpellChecker> shared_from_this()
  {
    return std::static_pointer_cast<TestWordBreakSpellChecker>(
        org.apache.lucene.util.LuceneTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/search/spell/
