#pragma once
#include "stringhelper.h"
#include <memory>

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
namespace org::apache::lucene::queries::function::valuesource
{

using ValueSource = org::apache::lucene::queries::function::ValueSource;

/**
 * Abstract parent class for those {@link ValueSource} implementations which
 * apply bool logic to their values
 */
class BoolFunction : public ValueSource
{
  GET_CLASS_NAME(BoolFunction)
  // TODO: placeholder to return type, among other common future functionality

protected:
  std::shared_ptr<BoolFunction> shared_from_this()
  {
    return std::static_pointer_cast<BoolFunction>(
        org.apache.lucene.queries.function.ValueSource::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/queries/function/valuesource/
