#pragma once
#include "stringhelper.h"
#include <memory>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/queryparser/flexible/core/nodes/QueryNode.h"

#include  "core/src/java/org/apache/lucene/queryparser/flexible/core/parser/EscapeQuerySyntax.h"

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

using EscapeQuerySyntax =
    org::apache::lucene::queryparser::flexible::core::parser::EscapeQuerySyntax;

/**
 * A {@link GroupQueryNode} represents a location where the original user typed
 * real parenthesis on the query string. This class is useful for queries like:
 * a) a AND b OR c b) ( a AND b) OR c
 *
 * Parenthesis might be used to define the bool operation precedence.
 */
class GroupQueryNode : public QueryNodeImpl
{
  GET_CLASS_NAME(GroupQueryNode)

  /**
   * This QueryNode is used to identify parenthesis on the original query string
   */
public:
  GroupQueryNode(std::shared_ptr<QueryNode> query);

  virtual std::shared_ptr<QueryNode> getChild();

  virtual std::wstring toString();

  std::shared_ptr<std::wstring>
  toQueryString(std::shared_ptr<EscapeQuerySyntax> escapeSyntaxParser) override;

  std::shared_ptr<QueryNode>
  cloneTree()  override;

  virtual void setChild(std::shared_ptr<QueryNode> child);

protected:
  std::shared_ptr<GroupQueryNode> shared_from_this()
  {
    return std::static_pointer_cast<GroupQueryNode>(
        QueryNodeImpl::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/queryparser/flexible/core/nodes/
