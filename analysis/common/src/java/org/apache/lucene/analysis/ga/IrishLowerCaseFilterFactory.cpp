using namespace std;

#include "IrishLowerCaseFilterFactory.h"
#include "../../../../../../../../../core/src/java/org/apache/lucene/analysis/TokenStream.h"
#include "../util/AbstractAnalysisFactory.h"
#include "IrishLowerCaseFilter.h"

namespace org::apache::lucene::analysis::ga
{
using TokenStream = org::apache::lucene::analysis::TokenStream;
using IrishLowerCaseFilter =
    org::apache::lucene::analysis::ga::IrishLowerCaseFilter;
using AbstractAnalysisFactory =
    org::apache::lucene::analysis::util::AbstractAnalysisFactory;
using MultiTermAwareComponent =
    org::apache::lucene::analysis::util::MultiTermAwareComponent;
using TokenFilterFactory =
    org::apache::lucene::analysis::util::TokenFilterFactory;

IrishLowerCaseFilterFactory::IrishLowerCaseFilterFactory(
    unordered_map<wstring, wstring> &args)
    : org::apache::lucene::analysis::util::TokenFilterFactory(args)
{
  if (!args.empty()) {
    throw invalid_argument(L"Unknown parameters: " + args);
  }
}

shared_ptr<TokenStream>
IrishLowerCaseFilterFactory::create(shared_ptr<TokenStream> input)
{
  return make_shared<IrishLowerCaseFilter>(input);
}

shared_ptr<AbstractAnalysisFactory>
IrishLowerCaseFilterFactory::getMultiTermComponent()
{
  return shared_from_this();
}
} // namespace org::apache::lucene::analysis::ga