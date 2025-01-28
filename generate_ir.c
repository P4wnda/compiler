#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/BitWriter.h>
#include <stddef.h>

int main() {
    // Create a module and function
    LLVMModuleRef module = LLVMModuleCreateWithName("my_module");
    LLVMTypeRef param_types[] = { LLVMInt32Type() };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), param_types, 0, 0);
    LLVMValueRef func = LLVMAddFunction(module, "main", func_type);

    // Create a basic block
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(func, "entry");
    LLVMBuilderRef builder = LLVMCreateBuilder();
    LLVMPositionBuilderAtEnd(builder, entry);

    // Create a return instruction
    LLVMValueRef ret_value = LLVMConstInt(LLVMInt32Type(), 42, 0);
    LLVMBuildRet(builder, ret_value);

    // Verify the module
    char* error = NULL;
    LLVMVerifyModule(module, LLVMAbortProcessAction, &error);

    // Print the IR
    LLVMDumpModule(module);

    // Clean up
    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(module);

    return 0;
}
