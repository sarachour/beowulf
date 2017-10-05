pragma solidity ^0.4.8;
contract PayToPlay {


  struct user {
    string name;
    account escrow;
  }

  mapping (address => user) accts;
  bool disabled;
  address dev;
  account dev_commission;


  function PayToPlay() internal {
    dev = msg.sender;
    disabled = false;
    dev_commission.open();
  }

  function make_acct(string name) public payable{
    if(disabled){revert();}
    if(bytes(accts[msg.sender].name).length == 0){
      accts[msg.sender].name = name;
      var escrow = accts[msg.sender].escrow;
      escrow.open();
      msg.wallet.transfer(dev_commission,1);
      msg.wallet.transfer(escrow,10);
      msg.wallet.transfer(escrow,msg.wallet.balance);
    }
  }

  function close_acct() public {
    if(disabled){revert();}
    if(bytes(accts[msg.sender].name).length != 0){
      var escrow = accts[msg.sender].escrow;
      escrow.transfer(dev_commission,1);
      escrow.transfer(msg.sender,escrow.balance);
      escrow.close();
    }
  }

  function disable() public {
    if(msg.sender == dev){
      disabled = true;
    }
  }

  function get_commission() public {
    if(msg.sender == dev){
      dev_commission.transfer(dev,dev_commission.balance);
    }
  }

  function () public {
    revert();
  }

}
