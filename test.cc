#include <tvm/build_module.h>
#include <tvm/tvm.h>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // define shape
    auto n = tvm::var("n");
    tvm::Array<tvm::Expr> shape;
    shape.push_back(n);

    // define algorithm
    auto A        = tvm::placeholder(shape, tvm::Float(32), "A");
    auto B        = tvm::placeholder(shape, tvm::Float(32), "B");
    tvm::Tensor C = tvm::compute(A->shape, [&A, &B](tvm::Expr i) { return A[i] + B[i]; }, "C");

    // set schedule
    tvm::Schedule s = tvm::create_schedule({C->op});

    tvm::BuildConfig config;
    auto target      = tvm::Target::create("llvm");
    auto target_host = tvm::Target::create("llvm");
    auto args        = tvm::Array<tvm::Tensor>({A, B, C});

    // what's this??
    // std::unordered_map<tvm::Tensor, tvm::Buffer> binds;

    // tvm::Array<tvm::LoweredFunc> lowered =
    //     tvm::lower(s, args, "fadd", binds, config);

    // // it might be a executable binary already compiled by JIT compiler
    // tvm::runtime::Module mod = tvm::build(lowered, target, target_host,
    // config); auto fadd = mod.GetFunction("fadd");

    // // show generated code
    // std::vector<tvm::runtime::Module> imported_modules = mod->imports();
    // cout << "==== Module code in LLVM ===" << endl;
    // cout << imported_modules[0]->GetSource() << endl;

    cout << "Success!!" << endl;
    return 0;
}