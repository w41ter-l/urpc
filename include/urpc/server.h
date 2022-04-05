// Copyright 2022 The urpc Authors.
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

#pragma once

#include <google/protobuf/service.h>

#include <memory>

#include "endpoint.h"

namespace urpc {

// Represent server's ownership of services.
enum ServiceOwnership { SERVER_OWNS_SERVICE, SERVER_DOESNT_OWN_SERVICE };

class ServerImpl;

class Server {
public:
    Server();
    ~Server();

    int Start(EndPoint ip_port);
    int Run();

    int AddService(google::protobuf::Service* service,
                   ServiceOwnership ownership);

private:
    std::unique_ptr<ServerImpl> impl_;
};

}  // namespace urpc