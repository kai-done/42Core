*This project has been created as part of the 42 curriculum by kkwek.*

Description: 
Born2beroot is using a virtual machine to learn about system administration, linux security and basic server configurations.
The goal is to understand how to use a virtual machine and how to configure it as a secure linux system.

Instructions: 

  1. Download Debian and setting up of virtual machine

     - setting up of hostname (name + 42)
     - setting root password and username (42 username)
     - setting up time zone clock
     - partition disks for non-bonus (guided - use entire disk and set up encryted LVM), seperate / home partition
     - Configure the package manager (no addditional packages required)
     - Installing the GRUB boot in the hard disk
    
  2. Login in to virtual machine and installing sudo

     - login with encryption password
     - login with root id & password
    
     - su is used to enter root
     - installing sudo and rebooting it
    
     - sudo su: enter root
     - sudo -V: verify sudo installation
     - sudo adduser <username>: add user, <username> is the name of the user
     - sudo addgroup <groupname>: add group, <groupname> is the name of the group
     - getent group <groupname>: check group and the user in it, <groupname> is the name of the group
     - sudo adduser <username> <groupname>: to add a user to the group, <username> is the name of the user, <groupname> is the name of the group
     - groups <username>: check the groups the user is in, <username> is the name of the user
     - sudo deluser <username>: delete a user, <username> is the name of the user
     - sudo deluser <username> <groupname>: remove the user from the group, <username> name of the user, <groupname> name of the group
     - sudo deluser --remove-home <username>: delete user and their home directory, <username> is the name of the user
     - sudo deluser --remove-all-files <username>: delete the account and tries to remove all files owned by the user, including files outside /home, <username> is the name of the user
    
     - getent group <groupname>: groupname:password:GID, user1, user2, user3
       - groupname: name of the group
       - password (usually x): historical field, not used anymore
       - GID: numeric group ID
       - user1, user2, user3: supplementary group members

  3. SSH: Secure Shell
     a secure way to connect to another computer over a network and control it from the command line
     SSH is a secure communication channel, it lets the user securely send commands and data between programs, not just open a remote terminal

     two sides to SSH:
       - client (ssh), prgram that runs to connect to another computer
         - how your outgoing connections behave
       - server (sshd), program that listens for incoming connections
         - how your incoming connections behave

     - Installing SSH first after updating the system
     - sudo service ssh status
     - modify both ssh config file in root [nano /etc/ssh/sshd_config] [nano /etc/ssh/ssh_config]
     - sudo service ssh restart, and checking the status again
     - adding the rule in the settings, at port forwarding, for both host and client
     - ssh <user>@localhost -p 4242 [connect via SSH from our machine]
    
  4. UFW (Firewall)

     UFW: Uncomplicated firewall
       - it is a simmpler firewall, easier for admins to control Linux firewall rules
       - it can be used on many different servers
       - typically deny all incoming connections unless explicitly allowed
       - can deny then allow a port, the port would become allowed, and vice versa

     - Installing ufw with apt and enabling it
     - allowing port 4242, meaning anyone can connect to the vm through port 4242, but still needing the username and password to log in
     - sudo ufw allow 4242: allowing port 4242, connection attempts reach the server, then authentication happens
     - sudo ufw delete allow 4242: deleting port 4242
     - sudo ufw deny 4242: denying port 4242, attempted connections from the port, never reach the server
     - sudo ufw status: checking the state of the firewall
    
  5. Sudo and password policies

     Who is sudoers?: 
       who is allowed to use sudo, and what they’re allowed to do with it.

     usermod -aG sudo <username>:
       “Add this user to the list allowed by sudoers.”

     sudo → the tool
     sudoers → the permission rules
     sudo group → a shortcut into sudoers

     small recap:
     mkdir -> make directory
     nano -> edit file
     touch -> create file

     /etc/sudoers       ← main sudo rules
     /etc/sudoers.d/    ← folder for custom rules (extra sudo configs)
     sudo_config        ← your custom config
     /var/log/sudo      ← folder for sudo logs

     - Defaults logfile="/var/log/sudo/sudo_config":
         - Sets a main sudo log file where sudo will record commands.
         - Tracks who ran sudo, what command, and when.

     - Defaults log_input, log_output
         - Enables full session recording:
              - log_input  → records everything typed during a sudo session (like keystrokes)
              - log_output → records everything displayed by the command
         - Think of it as a “snooping camera” on the sudo session, not just a text command log.
         - The logs are stored in iolog_dir (next line).
         ⚠️:
         - Can capture sensitive info typed in commands (including passwords if typed inside a program, not sudo itself).

     - Defaults iolog_dir="/var/log/sudo"
         - This is the directory where the full input/output logs go.
         - Each sudo session creates a subdirectory with the logs.
         - Every sudo session creates its own subdirectory in /var/log/sudo/.
         - Inside that directory, sudo stores:
             - iolog → everything you typed in that session
             - iolog output → everything the command printed to the terminal
         - If you run 10 sudo commands, you now have 10 session directories, each with multiple files.
         - The logs can grow very quickly, especially if you run interactive commands or commands that produce a lot of output.
      
     In a sense:
     - log_input = captures your hands on the keyboard
     - log_output = captures the screen
     - iolog_dir = where the footage is saved
    
     - Defaults requiretty
         - TTY: Teletype Terminal
        
  6. Script


apt normally doesn't need to be downloaded as compared to aptitude
apt is part of the base system for debian
aptitude is a seperate package that uses apt underneath

apt is the installer while aptitude is just another package
apt and apt-get -> official, default
aptitude -> alternate UI + dependancy resolver

Resources: 

  - born2beroot guide
  - markdown cheatsheet
  - SSH manual
  - man page
