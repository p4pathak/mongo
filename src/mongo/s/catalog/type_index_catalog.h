/**
 *    Copyright (C) 2023-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#pragma once

#include <string>
#include <vector>

#include "mongo/bson/timestamp.h"
#include "mongo/db/namespace_string.h"
#include "mongo/s/catalog/type_index_catalog_gen.h"
#include "mongo/util/uuid.h"

namespace mongo {

static constexpr auto kShardingIndexCatalogOplogEntryName = "modifyCollectionShardingIndexCatalog";

class ShardingIndexCatalogInsertEntry : public ShardingIndexCatalogInsertEntryBase {
public:
    ShardingIndexCatalogInsertEntry(const IndexCatalogType& idx);
};

class ShardingIndexCatalogRemoveEntry : public ShardingIndexCatalogRemoveEntryBase {
public:
    ShardingIndexCatalogRemoveEntry(const std::string& name,
                                    const UUID& uuid,
                                    const Timestamp& lastmod);
};

class ShardingIndexCatalogReplaceEntry : public ShardingIndexCatalogReplaceEntryBase {
public:
    ShardingIndexCatalogReplaceEntry(const UUID& uuid,
                                     const Timestamp& lastmod,
                                     const std::vector<IndexCatalogType>& i);
};

class ShardingIndexCatalogDropEntry : public ShardingIndexCatalogDropEntryBase {
public:
    ShardingIndexCatalogDropEntry(const UUID& uuid);
};

class ShardingIndexCatalogRenameEntry : public ShardingIndexCatalogRenameEntryBase {
public:
    ShardingIndexCatalogRenameEntry(const NamespaceString& fromNss,
                                    const NamespaceString& toNss,
                                    const Timestamp& lastmod);
};

class ShardingIndexCatalogClearEntry : public ShardingIndexCatalogClearEntryBase {
public:
    ShardingIndexCatalogClearEntry(const UUID& uuid);
};
}  // namespace mongo