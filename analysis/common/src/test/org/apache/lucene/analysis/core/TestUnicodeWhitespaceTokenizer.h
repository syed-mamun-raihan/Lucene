#pragma once
#include "../../../../../../../../../test-framework/src/java/org/apache/lucene/analysis/BaseTokenStreamTestCase.h"
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <deque>

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
namespace org::apache::lucene::analysis::core
{

using BaseTokenStreamTestCase =
    org::apache::lucene::analysis::BaseTokenStreamTestCase;

class TestUnicodeWhitespaceTokenizer : public BaseTokenStreamTestCase
{
  GET_CLASS_NAME(TestUnicodeWhitespaceTokenizer)

  // clone of test from WhitespaceTokenizer
public:
  virtual void testSimple() ;

  virtual void testNBSP() ;

  virtual void testFactory();

private:
  std::unordered_map<std::wstring, std::wstring>
  makeArgs(std::deque<std::wstring> &args);

public:
  virtual void testParamsFactory() ;

protected:
  std::shared_ptr<TestUnicodeWhitespaceTokenizer> shared_from_this()
  {
    return std::static_pointer_cast<TestUnicodeWhitespaceTokenizer>(
        org.apache.lucene.analysis.BaseTokenStreamTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/core/
