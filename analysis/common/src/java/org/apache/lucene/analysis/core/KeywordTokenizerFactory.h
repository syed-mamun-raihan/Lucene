#pragma once
#include "../util/TokenizerFactory.h"
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/core/KeywordTokenizer.h"

#include  "core/src/java/org/apache/lucene/util/AttributeFactory.h"

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

using TokenizerFactory = org::apache::lucene::analysis::util::TokenizerFactory;
using AttributeFactory = org::apache::lucene::util::AttributeFactory;

// C++ TODO: The Java 'import static' statement cannot be converted to C++:
//    import static
//    org.apache.lucene.analysis.standard.StandardTokenizer.MAX_TOKEN_LENGTH_LIMIT;

/**
 * Factory for {@link KeywordTokenizer}.
 * <pre class="prettyprint">
 * &lt;fieldType name="text_keyword" class="solr.TextField"
 * positionIncrementGap="100"&gt; &lt;analyzer&gt; &lt;tokenizer
 * class="solr.KeywordTokenizerFactory" maxTokenLen="256"/&gt; &lt;/analyzer&gt;
 * &lt;/fieldType&gt;</pre>
 *
 * Options:
 * <ul>
 *   <li>maxTokenLen: max token length, should be greater than 0 and less than
 *        MAX_TOKEN_LENGTH_LIMIT (1024*1024). It is rare to need to change this
 *      else {@link KeywordTokenizer}::DEFAULT_BUFFER_SIZE</li>
 * </ul>
 */
class KeywordTokenizerFactory : public TokenizerFactory
{
  GET_CLASS_NAME(KeywordTokenizerFactory)
private:
  const int maxTokenLen;

  /** Creates a new KeywordTokenizerFactory */
public:
  KeywordTokenizerFactory(std::unordered_map<std::wstring, std::wstring> &args);

  std::shared_ptr<KeywordTokenizer>
  create(std::shared_ptr<AttributeFactory> factory) override;

protected:
  std::shared_ptr<KeywordTokenizerFactory> shared_from_this()
  {
    return std::static_pointer_cast<KeywordTokenizerFactory>(
        org.apache.lucene.analysis.util.TokenizerFactory::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/core/
