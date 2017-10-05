
#include <libsolidity/beowulf/GrendelLib.h>
#include <libsolidity/codegen/CompilerContext.h>

using namespace std;
namespace dev
{
  namespace solidity
  {

    class BeowulfCompiler
    {
    public:
      BeowulfCompiler() {}
      static void injectGrendelLib(CompilerContext& m_context);
      static void unprivilegedStore(CompilerContext& m_context);
      static void unprivilegedLoad(CompilerContext& m_context);
      static void openAccount(CompilerContext& m_context);
      static void closeAccount(CompilerContext& m_context);
      static void getWallet(CompilerContext& m_context);
      static void transferAccount(CompilerContext& m_context);
      static void transferAddress(CompilerContext& m_context);
      static void call(CompilerContext& m_context);
    };

  }
}
