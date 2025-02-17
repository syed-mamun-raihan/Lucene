#pragma once
#include "stringhelper.h"
#include <memory>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/util/BytesRef.h"

#include  "core/src/java/org/apache/lucene/index/TermsEnum.h"

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

using BytesRef = org::apache::lucene::util::BytesRef;

/**
 * Subclass of FilteredTermsEnum for enumerating a single term.
 * <p>
 * For example, this can be used by {@link MultiTermQuery}s
 * that need only visit one term, but want to preserve
 * MultiTermQuery semantics such as {@link
 * MultiTermQuery#getRewriteMethod}.
 */
class SingleTermsEnum final : public FilteredTermsEnum
{
  GET_CLASS_NAME(SingleTermsEnum)
private:
  const std::shared_ptr<BytesRef> singleRef;

  /**
   * Creates a new <code>SingleTermsEnum</code>.
   * <p>
   * After calling the constructor the enumeration is already pointing to the
   * term, if it exists.
   */
public:
  SingleTermsEnum(std::shared_ptr<TermsEnum> tenum,
                  std::shared_ptr<BytesRef> termText);

protected:
  AcceptStatus accept(std::shared_ptr<BytesRef> term) override;

protected:
  std::shared_ptr<SingleTermsEnum> shared_from_this()
  {
    return std::static_pointer_cast<SingleTermsEnum>(
        FilteredTermsEnum::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/index/
