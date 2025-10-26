//Problem Statement(2043): You have been tasked with writing a program for a popular bank that will automate all its incoming 
//transactions (transfer, deposit, and withdraw). The bank has n accounts numbered from 1 to n. The initial balance of each 
//account is stored in a 0-indexed integer array balance, with the (i + 1)th account having an initial balance of balance[i].

//Time Complexity: O(1)
//Space Complexity: O(1)
class Bank {
    private long[] balance;
    private int n;

    public Bank(long[] balance) {
        this.balance = balance;
        this.n = balance.length;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (account > n) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (account > n || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */


//  Example Input
// ["Bank", "withdraw", "transfer", "deposit", "transfer"]
// [[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15]]

//  Example Output
//[null, true, true, true, false]