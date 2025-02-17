#pragma once
#include "stringhelper.h"
#include <memory>
#include <deque>

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

/**
 * <p>Expert: policy for deletion of stale {@link IndexCommit index commits}.
 *
 * <p>Implement this interface, and set it on
 * {@link IndexWriterConfig#setIndexDeletionPolicy(IndexDeletionPolicy)}
 * to customize when older
 * {@link IndexCommit point-in-time commits}
 * are deleted from the index directory.</p>
 *
 * <p>The default deletion policy
 * is {@link KeepOnlyLastCommitDeletionPolicy}, always
 * removes old commits as soon as a new commit is done (this
 * matches the behavior before 2.2).</p>
 *
 * <p>One expected use case for this (and the reason why it
 * was first created) is to work around problems with an
 * index directory accessed via filesystems like NFS because
 * NFS does not provide the "delete on last close" semantics
 * that Lucene's "point in time" search normally relies on.
 * By implementing a custom deletion policy, such as "a
 * commit is only removed once it has been stale for more
 * than X minutes", you can give your readers time to
 * refresh to the new commit before {@link IndexWriter}
 * removes the old commits.  Note that doing so will
 * increase the storage requirements of the index.  See <a
 * target="top"
 * href="http://issues.apache.org/jira/browse/LUCENE-710">LUCENE-710</a>
 * for details.</p>
 */

class IndexDeletionPolicy
    : public std::enable_shared_from_this<IndexDeletionPolicy>
{
  GET_CLASS_NAME(IndexDeletionPolicy)

  /** Sole constructor, typically called by sub-classes constructors. */
protected:
  IndexDeletionPolicy();

  /**
   * <p>This is called once when a writer is first
   * instantiated to give the policy a chance to remove old
   * commit points.</p>
   *
   * <p>The writer locates all index commits present in the
   * index directory and calls this method.  The policy may
   * choose to delete some of the commit points, doing so by
   * calling method {@link IndexCommit#delete delete()}
   * of {@link IndexCommit}.</p>
   *
   * <p><u>Note:</u> the last CommitPoint is the most recent one,
   * i.e. the "front index state". Be careful not to delete it,
   * unless you know for sure what you are doing, and unless
   * you can afford to lose the index content while doing that.
   *
   * @param commits List of current
   * {@link IndexCommit point-in-time commits},
   *  sorted by age (the 0th one is the oldest commit).
   *  Note that for a new index this method is invoked with
   *  an empty deque.
   */
public:
  template <typename T1>
  // C++ TODO: There is no native C++ template equivalent to this generic
  // constraint: ORIGINAL LINE: public abstract void onInit(java.util.List<?
  // extends IndexCommit> commits) throws java.io.IOException;
  void onInit(std::deque<T1> commits) = 0;

  /**
   * <p>This is called each time the writer completed a commit.
   * This gives the policy a chance to remove old commit points
   * with each commit.</p>
   *
   * <p>The policy may now choose to delete old commit points
   * by calling method {@link IndexCommit#delete delete()}
   * of {@link IndexCommit}.</p>
   *
   * <p>This method is only called when {@link
   * IndexWriter#commit} or {@link IndexWriter#close} is
   * called, or possibly not at all if the {@link
   * IndexWriter#rollback} is called.
   *
   * <p><u>Note:</u> the last CommitPoint is the most recent one,
   * i.e. the "front index state". Be careful not to delete it,
   * unless you know for sure what you are doing, and unless
   * you can afford to lose the index content while doing that.
   *
   * @param commits List of {@link IndexCommit},
   *  sorted by age (the 0th one is the oldest commit).
   */
  template <typename T1>
  // C++ TODO: There is no native C++ template equivalent to this generic
  // constraint: ORIGINAL LINE: public abstract void onCommit(java.util.List<?
  // extends IndexCommit> commits) throws java.io.IOException;
  void onCommit(std::deque<T1> commits) = 0;
};

} // #include  "core/src/java/org/apache/lucene/index/
