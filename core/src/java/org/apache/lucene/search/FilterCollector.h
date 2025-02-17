#pragma once
#include "stringhelper.h"
#include <memory>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/search/Collector.h"

#include  "core/src/java/org/apache/lucene/index/LeafReaderContext.h"
#include  "core/src/java/org/apache/lucene/search/LeafCollector.h"

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
namespace org::apache::lucene::search
{

using LeafReaderContext = org::apache::lucene::index::LeafReaderContext;

/**
 * {@link Collector} delegator.
 *
 * @lucene.experimental
 */
class FilterCollector : public std::enable_shared_from_this<FilterCollector>,
                        public Collector
{
  GET_CLASS_NAME(FilterCollector)

protected:
  const std::shared_ptr<Collector> in_;

  /** Sole constructor. */
public:
  FilterCollector(std::shared_ptr<Collector> in_);

  std::shared_ptr<LeafCollector> getLeafCollector(
      std::shared_ptr<LeafReaderContext> context)  override;

  virtual std::wstring toString();

  bool needsScores() override;
};

} // #include  "core/src/java/org/apache/lucene/search/
