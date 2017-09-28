pragma solidity ^0.4.8;
contract PayToPlay {

    function assert(bool clause) internal{
      if(clause == false){
        throw;
      }
    }


  struct user {
    string name;
    account escrow;
  }
  mapping (address => user) accts;
  bool disabled;
  address dev;
  account dev_commission;


  function PayToPlay(){
    dev = msg.sender;
    disabled = false;
    dev_commission.open();
  }

  function make_acct(string name) payable{
    if(disabled){throw;}
    if(bytes(accts[msg.sender].name).length == 0){
      accts[msg.sender].name = name;
      var escrow = accts[msg.sender].escrow;
      escrow.open()
      xfer(msg.wallet,dev_commission,1)
      xfer(msg.wallet,escrow,10)
      xfer(msg.wallet,escrow,msg.wallet.balance)
    }
  }

  function close_acct(){
    if(disabled){throw;}
    if(bytes(accts[msg.sender].name).length != 0){
      var escrow = accts[msg.sender].escrow;
      xfer(escrow,dev_commission,1);
      xfer(escrow,msg.sender,escrow.balance)
      escrow.close()
    }
  }

  function disable(){
    if(msg.sender == dev){
      disabled = true;
    }
  }

  function get_commission(){
    if(msg.sender == dev){
      xfer(dev_commission,dev,dev_commission.balance)
    }
  }

  function (){
    throw;
  }

}
