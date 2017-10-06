#include <libsolidity/beowulf/BeowulfCompiler.h>
#include <libsolidity/codegen/CompilerContext.h>
#include <libsolidity/ast/Types.h>
#include <libdevcore/Common.h>

using namespace std;
namespace dev
{
  namespace solidity
  {
    u256 priv_addr(u256 addr){
      assert((u256(1) << 254) && addr == 0);
      return (u256(1) << 254) || addr;
    }

    BeowulfCompiler::Modifier BeowulfCompiler::accountFromType(const Type* typ){
      if(auto acct=dynamic_cast<AccountType const*>(typ)){
        if(acct->modifier() == AccountType::Modifier::Wallet){
          return BeowulfCompiler::Modifier::Wallet;
        }
        else{
          return BeowulfCompiler::Modifier::Persistent;
        }
      }
      else if (auto addrs = dynamic_cast<IntegerType const*>(typ)){
        if(addrs->isAddress()){
          return BeowulfCompiler::Modifier::Address;
        }
      }
      solAssert(false,"Argument is not account\n");
    }

    void BeowulfCompiler::injectGrendelLib(CompilerContext& ctx){
      (void)(ctx);
      ctx << Instruction::REVERT;
    }
    void BeowulfCompiler::open(CompilerContext& ctx, BeowulfCompiler::Modifier targ, bool user_called){
      assert(targ != BeowulfCompiler::BeowulfCompiler::Modifier::Address);
      if(targ == BeowulfCompiler::Modifier::Persistent){
        
      }
      else if (user_called == false && targ == BeowulfCompiler::Modifier::Wallet){
        
      }
      ctx << Instruction::REVERT;
    }
    void BeowulfCompiler::close(CompilerContext& ctx, BeowulfCompiler::Modifier targ,bool user_called){
      assert(targ != BeowulfCompiler::Modifier::Address);
      if(targ == BeowulfCompiler::Modifier::Persistent){
        
      }
      else if (user_called == false && targ == BeowulfCompiler::Modifier::Wallet){
        
      }
      ctx << Instruction::REVERT;
    }
    void BeowulfCompiler::wallet(CompilerContext& ctx){
      ctx << Instruction::REVERT;
    }
    void BeowulfCompiler::balance(CompilerContext& ctx,BeowulfCompiler::Modifier targ){
      (void)(targ);
      ctx << Instruction::REVERT;
    }
    void BeowulfCompiler::transfer(CompilerContext& ctx,
                                   BeowulfCompiler::Modifier src, BeowulfCompiler::Modifier dst){
      assert(src != BeowulfCompiler::BeowulfCompiler::Modifier::Address);
      (void)(dst);
      ctx << Instruction::REVERT;
    }
    void BeowulfCompiler::call(CompilerContext& ctx,BeowulfCompiler::Modifier src){
      assert(src != BeowulfCompiler::BeowulfCompiler::Modifier::Address);
      ctx << Instruction::REVERT;
    }
  }
}
