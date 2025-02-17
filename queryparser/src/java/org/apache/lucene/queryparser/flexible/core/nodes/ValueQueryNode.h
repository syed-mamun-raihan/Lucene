#pragma once
#include "stringhelper.h"
#include <type_traits>

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
namespace org::apache::lucene::queryparser::flexible::core::nodes
{

/**
 * This interface should be implemented by {@link QueryNode} that holds an
 * arbitrary value.
 */
template <typename T>
class ValueQueryNode : public QueryNode
{
  GET_CLASS_NAME(ValueQueryNode)
  static_assert(std::is_base_of<std::any, T>::value,
                L"T must inherit from std::any");

public:
  virtual void setValue(T value) = 0;

  virtual T getValue() = 0;
};

} // #include  "core/src/java/org/apache/lucene/queryparser/flexible/core/nodes/
