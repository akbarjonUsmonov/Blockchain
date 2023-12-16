# Welcome to My Blockchain
***

## Description
    Blockchain is a command that allows for the creation and management of a blockchain.
    When the program starts (it loads a backup if there is one) then a prompt appears.
    This prompt allows to execute commands. When the commands are successful they display
    "ok" and if not, "nok: info" or info is an error message:
      
        ● add node nid add a nid identifier to the blockchain node.
        ● rm node nid... remove nodes from the blockchain with a nid identifier. If nid is '*', then all nodes are impacted.
        ● add block bid nid... add a bid identifier block to nodes identified by nid. If nid is '*', then all nodes are impacted.
        ● rm block bid... remove the bid identified blocks from all nodes where these blocks are present.
        ● ls list all nodes by their identifiers. The option -l attaches the blocks bid's associated with each node.
        ● sync synchronize all of the nodes with each other. Upon issuing this command, all of the nodes are composed of the same blocks.
        ● quit save and leave the blockchain.

The blockchain prompt displays:
    ● "s" if the blockchain is synchronized.   >>       [s<n>]>
    ●  "-" if the blockchain is not synchronized.  >>   [-s<n>]>
    ●  "n" number of nodes in the chain.

## Installation
    To run this program user can use GNU complilation gcc command or Makefile that i provided
        $>make
        $>./my_blockchain
        No Backup Found: Starting New Blockchain
        [s0]> Execute commands

        Note: to remove binary file of Makefile use command "make clean" ;-)

## Usage
    ● Technical Information:

        $>make
        $>my_blockchain
        No Backup Found: Starting New Blockchain
        [s0]> add node 12
        OK
        [s1]> add block 21 *
        OK
        [s1]> add node 13
        OK
        [-2]> sync
        OK
        [s2]> ls -l
        12: 21
        13: 21
        [s2]> quit
        Backing up blockchain...

### The Core Team
Akbar Usmonov
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
