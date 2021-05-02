#include <node.h>
#include <iostream>
#include <filesystem>

namespace core {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    using namespace std;
    using namespace std::filesystem;
    using namespace std::chrono;

    void Method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world").ToLocalChecked());
    }

    void Test(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "hello", Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}