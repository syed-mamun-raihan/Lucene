#pragma once
#include "../../../../../../../../../core/src/java/org/apache/lucene/analysis/Analyzer.h"
#include "../../../../../../../../../test-framework/src/java/org/apache/lucene/analysis/BaseTokenStreamTestCase.h"
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/Analyzer.h"

#include  "core/src/java/org/apache/lucene/analysis/TokenStreamComponents.h"

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
namespace org::apache::lucene::analysis::br
{

using Analyzer = org::apache::lucene::analysis::Analyzer;
using BaseTokenStreamTestCase =
    org::apache::lucene::analysis::BaseTokenStreamTestCase;

/**
 * Test the Brazilian Stem Filter, which only modifies the term text.
 *
 * It is very similar to the snowball portuguese algorithm but not exactly the
 * same.
 *
 */
class TestBrazilianAnalyzer : public BaseTokenStreamTestCase
{
  GET_CLASS_NAME(TestBrazilianAnalyzer)

public:
  virtual void testWithSnowballExamples() ;

  virtual void testNormalization() ;

  virtual void testReusableTokenStream() ;

  virtual void testStemExclusionTable() ;

  virtual void testWithKeywordAttribute() ;

private:
  void check(const std::wstring &input,
             const std::wstring &expected) ;

  void checkReuse(std::shared_ptr<Analyzer> a, const std::wstring &input,
                  const std::wstring &expected) ;

  /** blast some random strings through the analyzer */
public:
  virtual void testRandomStrings() ;

  virtual void testEmptyTerm() ;

private:
  class AnalyzerAnonymousInnerClass : public Analyzer
  {
    GET_CLASS_NAME(AnalyzerAnonymousInnerClass)
  private:
    std::shared_ptr<TestBrazilianAnalyzer> outerInstance;

  public:
    AnalyzerAnonymousInnerClass(
        std::shared_ptr<TestBrazilianAnalyzer> outerInstance);

  protected:
    std::shared_ptr<Analyzer::TokenStreamComponents>
    createComponents(const std::wstring &fieldName) override;

  protected:
    std::shared_ptr<AnalyzerAnonymousInnerClass> shared_from_this()
    {
      return std::static_pointer_cast<AnalyzerAnonymousInnerClass>(
          org.apache.lucene.analysis.Analyzer::shared_from_this());
    }
  };

protected:
  std::shared_ptr<TestBrazilianAnalyzer> shared_from_this()
  {
    return std::static_pointer_cast<TestBrazilianAnalyzer>(
        org.apache.lucene.analysis.BaseTokenStreamTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/br/
