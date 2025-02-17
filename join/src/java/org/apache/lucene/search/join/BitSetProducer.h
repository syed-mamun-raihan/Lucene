#pragma once
#include "stringhelper.h"
#include <memory>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/index/LeafReaderContext.h"

#include  "core/src/java/org/apache/lucene/util/BitSet.h"

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
namespace org::apache::lucene::search::join
{

using LeafReaderContext = org::apache::lucene::index::LeafReaderContext;
using BitSet = org::apache::lucene::util::BitSet;

/**
 * A producer of {@link BitSet}s per segment.
 */
class BitSetProducer
{
  GET_CLASS_NAME(BitSetProducer)

  /**
   * Produce a {@link BitSet} matching the expected documents on the given
   * segment. This may return {@code null} if no documents match.
   */
public:
  virtual std::shared_ptr<BitSet>
  getBitSet(std::shared_ptr<LeafReaderContext> context) = 0;
};

} // #include  "core/src/java/org/apache/lucene/search/join/
