// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <mongocxx/options/distinct.hpp>

#include <mongocxx/private/read_preference.hh>

#include <mongocxx/config/private/prelude.hh>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace options {

distinct& distinct::collation(bsoncxx::document::view_or_value collation) {
    _collation = std::move(collation);
    return *this;
}

distinct& distinct::max_time(std::chrono::milliseconds max_time) {
    _max_time = std::move(max_time);
    return *this;
}

distinct& distinct::read_preference(class read_preference rp) {
    _read_preference = std::move(rp);
    return *this;
}

const stdx::optional<bsoncxx::document::view_or_value>& distinct::collation() const {
    return _collation;
}

const stdx::optional<std::chrono::milliseconds>& distinct::max_time() const {
    return _max_time;
}

const stdx::optional<class read_preference>& distinct::read_preference() const {
    return _read_preference;
}

bool MONGOCXX_CALL operator==(const distinct& lhs, const distinct& rhs) {
    return ((lhs.collation() == rhs.collation()) && (lhs.max_time() == rhs.max_time()) &&
            (lhs.read_preference() == rhs.read_preference()));
}
bool MONGOCXX_CALL operator!=(const distinct& lhs, const distinct& rhs) {
    return !(lhs == rhs);
}

}  // namespace options
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx