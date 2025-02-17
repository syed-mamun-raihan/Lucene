#pragma once
#include "../../../../../../../../../core/src/java/org/apache/lucene/analysis/TokenFilter.h"
#include "stringhelper.h"
#include <memory>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/en/KStemmer.h"

#include  "core/src/java/org/apache/lucene/analysis/tokenattributes/CharTermAttribute.h"
#include  "core/src/java/org/apache/lucene/analysis/tokenattributes/KeywordAttribute.h"
#include  "core/src/java/org/apache/lucene/analysis/TokenStream.h"

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
namespace org::apache::lucene::analysis::en
{

using TokenFilter = org::apache::lucene::analysis::TokenFilter;
using TokenStream = org::apache::lucene::analysis::TokenStream;
using CharTermAttribute =
    org::apache::lucene::analysis::tokenattributes::CharTermAttribute;
using KeywordAttribute =
    org::apache::lucene::analysis::tokenattributes::KeywordAttribute;

/** A high-performance kstem filter for english.
 * <p>
 * See <a href="http://ciir.cs.umass.edu/pubfiles/ir-35.pdf">
 * "Viewing Morphology as an Inference Process"</a>
 * (Krovetz, R., Proceedings of the Sixteenth Annual International ACM SIGIR
 * Conference on Research and Development in Information Retrieval, 191-203,
 * 1993). <p> All terms must already be lowercased for this filter to work
 * correctly.
 *
 * <p>
 * Note: This filter is aware of the {@link KeywordAttribute}. To prevent
 * certain terms from being passed to the stemmer
 * {@link KeywordAttribute#isKeyword()} should be set to <code>true</code>
 * in a previous {@link TokenStream}.
 *
 * Note: For including the original term as well as the stemmed version, see
 * {@link org.apache.lucene.analysis.miscellaneous.KeywordRepeatFilterFactory}
 * </p>
 *
 *
 */

class KStemFilter final : public TokenFilter
{
  GET_CLASS_NAME(KStemFilter)
private:
  const std::shared_ptr<KStemmer> stemmer = std::make_shared<KStemmer>();
  const std::shared_ptr<CharTermAttribute> termAttribute =
      addAttribute(CharTermAttribute::typeid);
  const std::shared_ptr<KeywordAttribute> keywordAtt =
      addAttribute(KeywordAttribute::typeid);

public:
  KStemFilter(std::shared_ptr<TokenStream> in_);

  /** Returns the next, stemmed, input Token.
   *  @return The stemmed form of a token.
   *  @throws IOException If there is a low-level I/O error.
   */
  bool incrementToken()  override;

protected:
  std::shared_ptr<KStemFilter> shared_from_this()
  {
    return std::static_pointer_cast<KStemFilter>(
        org.apache.lucene.analysis.TokenFilter::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/en/
