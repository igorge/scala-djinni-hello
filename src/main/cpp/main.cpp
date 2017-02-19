#include "generated/hello_world.hpp"
#include "generated/hello_world_maker.hpp"

namespace gie {

    struct HelloWorldImpl : HelloWorld {

        int32_t m_v;

        HelloWorldImpl(int32_t v) : m_v(v) {}

        int32_t do_hello_world(const std::string &key) override {
            printf("do_hello_world: %s", key.c_str());
            return m_v;
        }

    };


    std::shared_ptr<HelloWorld> HelloWorldMaker::make(int32_t v) {

        return std::make_shared<HelloWorldImpl>(v);

    }
}