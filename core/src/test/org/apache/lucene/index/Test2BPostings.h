#pragma once
#include "stringhelper.h"
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/tokenattributes/CharTermAttribute.h"

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
namespace org::apache::lucene::index
{

using TokenStream = org::apache::lucene::analysis::TokenStream;
using CharTermAttribute =
    org::apache::lucene::analysis::tokenattributes::CharTermAttribute;
using LuceneTestCase = org::apache::lucene::util::LuceneTestCase;

/**
 * Test indexes ~82M docs with 26 terms each, so you get &gt; Integer.MAX_VALUE
 * terms/docs pairs
 * @lucene.experimental
 */
// C++ TODO: Most Java annotations will not have direct C++ equivalents:
// ORIGINAL LINE: @SuppressCodecs({ "SimpleText", "Memory", "Direct",
// "Compressing" }) @TimeoutSuite(millis = 4 * TimeUnits.HOUR) public class
// Test2BPostings extends org.apache.lucene.util.LuceneTestCase
class Test2BPostings : public LuceneTestCase
{
public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Nightly public void test() throws Exception
  virtual void test() ;

public:
  class MyTokenStream final : public TokenStream
  {
    GET_CLASS_NAME(MyTokenStream)
  private:
    const std::shared_ptr<CharTermAttribute> termAtt =
        addAttribute(CharTermAttribute::typeid);

  public:
    int index = 0;

    bool incrementToken() override;

    void reset() override;

  protected:
    std::shared_ptr<MyTokenStream> shared_from_this()
    {
      return std::static_pointer_cast<MyTokenStream>(
          org.apache.lucene.analysis.TokenStream::shared_from_this());
    }
  };

protected:
  std::shared_ptr<Test2BPostings> shared_from_this()
  {
    return std::static_pointer_cast<Test2BPostings>(
        org.apache.lucene.util.LuceneTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/index/
