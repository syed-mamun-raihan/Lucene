#pragma once
#include "stringhelper.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <memory>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/search/similarities/BasicStats.h"

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
namespace org::apache::lucene::search::similarities
{

// C++ TODO: The Java 'import static' statement cannot be converted to C++:
//    import static org.apache.lucene.search.similarities.SimilarityBase.log2;

/**
 * Limiting form of the Bose-Einstein model. The formula used in Lucene differs
 * slightly from the one in the original paper: {@code F} is increased by {@code
 * tfn+1} and {@code N} is increased by {@code F}
 * @lucene.experimental
 * NOTE: in some corner cases this model may give poor performance or infinite
 * scores with Normalizations that return large or small values for {@code tfn}
 * such as NormalizationH3. Consider using the geometric approximation ({@link
 * BasicModelG}) instead, which provides the same relevance but with less
 * practical problems.
 */
class BasicModelBE : public BasicModel
{
  GET_CLASS_NAME(BasicModelBE)

  /** Sole constructor: parameter-free */
public:
  BasicModelBE();

  float score(std::shared_ptr<BasicStats> stats, float tfn) override final;

  /** The <em>f</em> helper function defined for <em>B<sub>E</sub></em>. */
private:
  double f(double n, double m);

public:
  virtual std::wstring toString();

protected:
  std::shared_ptr<BasicModelBE> shared_from_this()
  {
    return std::static_pointer_cast<BasicModelBE>(
        BasicModel::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/search/similarities/
