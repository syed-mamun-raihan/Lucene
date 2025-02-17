#pragma once
#include "stringhelper.h"
#include <memory>
#include <optional>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/index/Terms.h"

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
namespace org::apache::lucene::classification::utils
{

using Terms = org::apache::lucene::index::Terms;

/**
 * utility class for converting Lucene {@link
 * org.apache.lucene.document.Document}s to <code>Double</code> vectors.
 */
class DocToDoubleVectorUtils
    : public std::enable_shared_from_this<DocToDoubleVectorUtils>
{
  GET_CLASS_NAME(DocToDoubleVectorUtils)

private:
  DocToDoubleVectorUtils();

  /**
   * create a sparse <code>Double</code> deque given doc and field term vectors
   * using local frequency of the terms in the doc
   *
   * @param docTerms   term vectors for a given document
   * @param fieldTerms field term vectors
   * @return a sparse deque of <code>Double</code>s as an array
   * @throws IOException in case accessing the underlying index fails
   */
public:
  static std::deque<std::optional<double>> toSparseLocalFreqDoubleArray(
      std::shared_ptr<Terms> docTerms,
      std::shared_ptr<Terms> fieldTerms) ;

  /**
   * create a dense <code>Double</code> deque given doc and field term vectors
   * using local frequency of the terms in the doc
   *
   * @param docTerms term vectors for a given document
   * @return a dense deque of <code>Double</code>s as an array
   * @throws IOException in case accessing the underlying index fails
   */
  static std::deque<std::optional<double>> toDenseLocalFreqDoubleArray(
      std::shared_ptr<Terms> docTerms) ;
};

} // #include  "core/src/java/org/apache/lucene/classification/utils/
