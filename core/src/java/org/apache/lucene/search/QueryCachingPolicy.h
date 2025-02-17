#pragma once
#include "stringhelper.h"
#include <memory>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/search/Query.h"

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

/**
 * A policy defining which filters should be cached.
 *
 * Implementations of this class must be thread-safe.
 *
 * @see UsageTrackingQueryCachingPolicy
 * @see LRUQueryCache
 * @lucene.experimental
 */
// TODO: add APIs for integration with IndexWriter.IndexReaderWarmer
class QueryCachingPolicy
{
  GET_CLASS_NAME(QueryCachingPolicy)

  /** A simple policy that caches all the provided filters on all segments.
   *  @deprecated This policy is inefficient as caching too aggressively
   *  disables the ability to skip non-interesting documents. See
   *  {@link UsageTrackingQueryCachingPolicy}. */
public:
  // C++ TODO: Most Java annotations will not have direct C++ equivalents:
  // ORIGINAL LINE: @Deprecated public static final QueryCachingPolicy
  // ALWAYS_CACHE = new QueryCachingPolicy()
  static const std::shared_ptr<QueryCachingPolicy> ALWAYS_CACHE;

  /** Callback that is called every time that a cached filter is used.
   *  This is typically useful if the policy wants to track usage statistics
   *  in order to make decisions. */
  virtual void onUse(std::shared_ptr<Query> query) = 0;

  /** Whether the given {@link Query} is worth caching.
   *  This method will be called by the {@link QueryCache} to know whether to
   *  cache. It will first attempt to load a {@link DocIdSet} from the cache.
   *  If it is not cached yet and this method returns <tt>true</tt> then a
   *  cache entry will be generated. Otherwise an uncached scorer will be
   *  returned. */
  virtual bool shouldCache(std::shared_ptr<Query> query) = 0;
};

class QueryCachingPolicyAnonymousInnerClass
    : public std::enable_shared_from_this<
          QueryCachingPolicyAnonymousInnerClass>,
      public QueryCachingPolicy
{
  GET_CLASS_NAME(QueryCachingPolicyAnonymousInnerClass)
public:
  QueryCachingPolicyAnonymousInnerClass();

  void onUse(std::shared_ptr<Query> query) override;
  bool shouldCache(std::shared_ptr<Query> query)  override;
};
} // #include  "core/src/java/org/apache/lucene/search/
