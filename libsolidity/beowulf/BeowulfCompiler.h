
#include <libsolidity/beowulf/GrendelLib.h>
#include <libsolidity/codegen/CompilerContext.h>

using namespace std;
namespace dev
{
  namespace solidity
  {

    class BeowulfCompiler
    {
      enum class Modifier {
        Wallet,Address,Persistent 
      };
    public:
      BeowulfCompiler() {}
      static Modifier accountFromType(const Type* typ);
      static void injectGrendelLib(CompilerContext& m_context);
      static void open(CompilerContext& m_context, Modifier targ,bool user);
      static void close(CompilerContext& m_context, Modifier targ,bool user);
      static void wallet(CompilerContext& m_context);
      static void balance(CompilerContext& m_context,Modifier targ);
      static void transfer(CompilerContext& m_context,Modifier src, Modifier dst);
      static void call(CompilerContext& m_context,Modifier targ);
    };

  }
}
