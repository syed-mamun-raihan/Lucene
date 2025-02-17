#pragma once
#include "stringhelper.h"
#include <any>
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
namespace org::apache::lucene::analysis::cn::smart::hhmm
{

/**
 * SmartChineseAnalyzer internal node representation
 * <p>
 * Used by {@link BiSegGraph} to maximize the segmentation with the Viterbi
 * algorithm.
 * </p>
 * @lucene.experimental
 */
class PathNode : public std::enable_shared_from_this<PathNode>,
                 public Comparable<std::shared_ptr<PathNode>>
{
  GET_CLASS_NAME(PathNode)
public:
  double weight = 0;

  int preNode = 0;

  int compareTo(std::shared_ptr<PathNode> pn) override;

  /**
   * @see java.lang.Object#hashCode()
   */
  virtual int hashCode();

  /**
   * @see java.lang.Object#equals(java.lang.Object)
   */
  bool equals(std::any obj) override;
};

} // #include  "core/src/java/org/apache/lucene/analysis/cn/smart/hhmm/
