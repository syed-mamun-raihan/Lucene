#pragma once
#include "../../../../../../../../common/src/java/org/apache/lucene/analysis/util/TokenFilterFactory.h"
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/phonetic/DoubleMetaphoneFilter.h"

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
namespace org::apache::lucene::analysis::phonetic
{

using TokenStream = org::apache::lucene::analysis::TokenStream;
using DoubleMetaphoneFilter =
    org::apache::lucene::analysis::phonetic::DoubleMetaphoneFilter;
using TokenFilterFactory =
    org::apache::lucene::analysis::util::TokenFilterFactory;

/**
 * Factory for {@link DoubleMetaphoneFilter}.
 * <pre class="prettyprint">
 * &lt;fieldType name="text_dblmtphn" class="solr.TextField"
 * positionIncrementGap="100"&gt; &lt;analyzer&gt; &lt;tokenizer
 * class="solr.WhitespaceTokenizerFactory"/&gt; &lt;filter
 * class="solr.DoubleMetaphoneFilterFactory" inject="true"
 * maxCodeLength="4"/&gt; &lt;/analyzer&gt; &lt;/fieldType&gt;</pre>
 */
class DoubleMetaphoneFilterFactory : public TokenFilterFactory
{
  GET_CLASS_NAME(DoubleMetaphoneFilterFactory)
  /** parameter name: true if encoded tokens should be added as synonyms */
public:
  static const std::wstring INJECT;
  /** parameter name: restricts the length of the phonetic code */
  static const std::wstring MAX_CODE_LENGTH;
  /** default maxCodeLength if not specified */
  static constexpr int DEFAULT_MAX_CODE_LENGTH = 4;

private:
  const bool inject;
  const int maxCodeLength;

  /** Creates a new DoubleMetaphoneFilterFactory */
public:
  DoubleMetaphoneFilterFactory(
      std::unordered_map<std::wstring, std::wstring> &args);

  std::shared_ptr<DoubleMetaphoneFilter>
  create(std::shared_ptr<TokenStream> input) override;

protected:
  std::shared_ptr<DoubleMetaphoneFilterFactory> shared_from_this()
  {
    return std::static_pointer_cast<DoubleMetaphoneFilterFactory>(
        org.apache.lucene.analysis.util.TokenFilterFactory::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/phonetic/
