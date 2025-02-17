#pragma once
#include "stringhelper.h"
#include <memory>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/analysis/util/AbstractAnalysisFactory.h"

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

/** Add to any analysis factory component to allow returning an
 * analysis component factory for use with partial terms in prefix queries,
 * wildcard queries, range query endpoints, regex queries, etc.
 *
 * Components implementing this interface should not add or remove tokens from
 * the token stream, and should be able to deal with special characters
 * indicating that multi-term queries are required (eg slashes for regex,
 * wildcard characters, etc)
 *
 * @lucene.experimental
 */
class MultiTermAwareComponent
{
  GET_CLASS_NAME(MultiTermAwareComponent)
  /** Returns an analysis component to handle analysis if multi-term queries.
   * The returned component must be a TokenizerFactory, TokenFilterFactory or
   * CharFilterFactory.
   */
public:
  virtual std::shared_ptr<AbstractAnalysisFactory> getMultiTermComponent() = 0;
};

} // #include  "core/src/java/org/apache/lucene/analysis/util/
