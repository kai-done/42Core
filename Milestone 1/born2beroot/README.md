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
    
  5. Sudo policies

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
         - TTY: Teletypewriter
         - sudo can only be run from an interactive terminal (TTY)
      
         - An interactive terminal (TTY) is a session where:
             - you type commands
             - you see output immediately
             - the system knows someone is there
          
         - Examples that count:
            - Logging into the VM and getting a shell prompt
            - SSH’ing into the machine and typing commands
            - Using the VM’s console window
          
     - Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
         - When running commands with sudo, ignore the user’s PATH and use this one instead.
         - prevents the VM from being hacked or messed up
         - protects the VM from accidental or sneaky misuse of sudo
        
  6. Password policies

     - /etc/logins.defs -> a system config that controls login and password policies
     - modify password parameters for pass_max_days and pass_min_days
    
     - PASS_MAX_DAYS: Maximum number of days before password expires.
     - PASS_MIN_DAYS: Minimum number of days before password can be changed.
     - PASS_WARN_AGE: Number of days before password expiration to show warning.
    
     - installing password quality library: sudo apt install libpam-pwquality
     - it installs a PAM module (pam_pwqality.so) that checks how strong passwords are when users:
         - change passwords
         - create new users
         - reset passwords
     - PAM = Pluggable Authentication Modules
     - shared libraries in Linux/UNIX that allow administrators to configure authentication policies—like password complexity, aging, and locking—without modifying application code
     - They centralize security, enabling, for example, pam_pwquality to enforce password strength across SSH, login, and su services
    
     - once pwquality is enabled, it requries things like:
         - minimum password length
         - mix of upper/lowercase letters
         - numbers and symbols
         - rejection of common or simple passwords
         - limits on repeated or sequential character
    
     - /etc/pam.d/common-password
         - belongs to PAM
         - controls what happens when a password is set or changed
         - handle things like:
             - password strength checks
             - passwords reuse rules
             - how passwords are stored
    
     - minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
         - minlen: password must be at least <> characters long
         - ucredit: at least <> uppercase letter
         - dcredit: at least <> digit
         - lcredit: at least <> lowercase letter
         - maxrepeat: prevents more than <> identical characters in a row
         - reject_username: disallows passwords that contain the username
         - difok: at least <> characters must be different from the old password
         - enforce_for_root: applies the same rules to root
    
  7. Script

     - nano monitoring.sh
    
     - architecture: uname -a
       - the design of how the cpu works
       - cpu is like the brain of the computer
         
     - Physical cores: grep "physical id" /proc/cpuinfo | wc -l
       - physical cores are in the cpu
       - when asking for physical cores amount, it is the same as asking for how many processors are inside the cpu, similar to asking how many instructions the CPU can handle at the same time

     - Virtual cores: grep processor /proc/cpuinfo | wc -l
       - make a single physical core appear like it's doing much more than one job at the same time
       - making the physical core to act as though there are many other cores in it

     - RAM: free
       - Random Access Memory
       - have mem and swap
       - it is temporary storage itself, the data stored in ram is deleted when computer is switch off
       - total RAM (mem) --> [free --mega | awk '$1 == "Mem:" {print $2}']
       - used mem RAM --> [free --mega | awk '$1 == "Mem:" {print $3}']
       - utilization rate --> (used/total) x 100 --> [free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}']

     - Storage: df (disk free)
       - long term space to store files, programs and data
       - keep data even when computer switch off
       - utilization rate --> [df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}']
           - grep -v "/boot": The -v flag makes grep invert the match (i.e., exclude lines containing /boot)
           - END: The END block is part of the awk programming language. It’s used to specify actions that should happen after all the input has been processed.
       - utalization rate of processors = CPU utilization rate : vmstat
       - CPU utilization = 100% - Idle%
       - Low CPU utilization (near 0%) means your system is mostly idle and has resources to handle more tasks.
       - High CPU utilization (near 100%) means the CPU is working at full capacity, which might slow down the system if more tasks are added.
       - If CPU utilization is constantly high, it can indicate that your system is under heavy load, or there may be an inefficient process consuming too much CPU time.
       - [vmstat 1 4 | tail -1 | awk '{print 100 - $15}']
           - vmstat: The vmstat command reports information about system performance, including virtual memory, processes, CPU activity, etc.
           - 1: means the command will update every 1 second.
           - 4: means it will run for 4 iterations, providing data 4 times in total (one every second).
           - tail -1: This command takes the output of the previous vmstat 1 4 command and gets only the last line (the final iteration of stats).
       - 100 - result = cpu ult rate
         
     - Date and Time of last reboot: uptime -s
       - [who -b | awk '$1 == "system" {print $3 " " $4}']
         
     - LVM (Logical Volume Manager) : sudo lvscan
       - storage manager in a sense... very flexible and dynamic...
       - [if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi]
           - lsblk: The lsblk command lists all available block devices on your system (like hard drives, partitions, and other storage devices).
           - $(...): The $() syntax is command substitution, which means that it runs the command inside and returns the result.
           - [ ... ] (test condition): The square brackets [...] are used to test a condition in a shell script.
           - if ... then ... else ... fi: This is the structure of an if-else statement in Bash.
           - -gt: means "greater than" in Bash
           - -gt 0: is checking if it's greater than 0
        
       - lsblk | grep lvm
       - ** lsblk needed for bonus

     - check active connections: who | wc -l
     - check active unique users : who |awk '{print $1}' | sort | uniq | wc -l
       - connections/sessions --> how many "seats" are being used
       - users --> how many "people" are sitting, ignoring if someone is sitting in 2 seats

           - who : lists all logged in-users and where
           - awk '{print $1}' : takes only the username column
           - sort | uniq : removes duplicates
           - wc = word count : counts things in text, by default can count lines, words and characters
           - -l : means "count the number of lines"
    
     - IPv4 and Mac addresses:
        - IPv4: ip -4 addr show enp0s3 | grep inet | awk '{print $2}' | cut -d/ -f1
        - MAC: ip link show enp0s3 | grep ether | awk '{print $2}'
      
        - IPv4: your "house address" on the internet
        - MAC: your network card's "serial number"
      
          - ip addr show : list all network interfaces and their info
          - -4 : show only IPv4 addresses
          - enp0s3 : show only info for this network interface
          - | = "pipe" : send output of previous command to the next command
          - grep inet : filter only lines containing inet
          - awk : a tool to process columns of text
          - {print $2} : to print the 2nd column of the line
          - cut : split text into pieces
          - -d/ : use / as the delimiter (splits 10.0.2.15/24 into 10.0.2.15 and 24)
          - -f1 : take the first piece
          - ip link show : cleaner and more standard for MAC Addresses
         
        - IPv4 + MAC : echo "IPv4: $(ip -4 addr show enp0s3 | grep inet | awk '{print $2}' | cut -d/ -f1)  MAC: $(ip link show enp0s3 | grep ether | awk '{print $2}')"
      
     - number of commands executed with the sudo program: sudo journalctl | grep 'sudo' | wc -l
     - means it is checking how many times sudo is used or called, so anything like "sudo ..." will be counted
         - sudo : to access root/admin privileges to read system logs
         - journalctl : a tool for reading the systemd journal, a big log of system events
     - initial sudo running the command itself is not counted, as it is used to just run the command and read the logs
     - journalctl _COMM=sudo | grep COMMAND | wc -l
         - journalctl _COMM=sudo: This command filters logs from journalctl specifically for entries where the communication (_COMM) was made by the sudo command. This means the logs are limited to entries where sudo was actually run, which can be useful if you're specifically interested in actions that involved sudo commands.
         - grep COMMAND: After getting the logs that involve sudo, this part filters those logs further to only include lines containing the word COMMAND. COMMAND here is likely meant to refer to the specific action that was executed by sudo, like apt-get update or any other command that was run via sudo.

  9. Crontab & Signature.txt

     - sudo crontab -u root -e
         - crontab: manage cron jobs (scheduled commands)
         -  -u root: target the root user's cron tab
         -  -e: edit it
    
     - crontab -e: runs as current user
     - sudo crontab -u root -e: runs as root
    
     - cron timing format:
         * * * * * command
         | | | | |
         | | | | +-- day of week (0–7, Sun)
         | | | +---- month (1–12)            
         | | +------ day of month (1–31)
         | +-------- hour (0–23)
         +---------- minute (0–59)
  
     - root's crontab runs with full privileges
     - does not need sudo inside commands
     - can modify system files, users, services
    
     - */10 * * * * sh /path_to_file.sh
         - runs every 10 minutes at all time
         - sh: shell interpreter
         - sh /path_to_file.sh: means “Hey shell, please read /path_to_file.sh and run the commands inside it.”
         - Cron jobs don’t automatically know what shell to use.
         - By explicitly calling sh, you ensure that the script runs in a shell.
         - /path_to_file.sh: the full actual path to the *.sh file
         - ways to find the pathway to the file:
             - pwd
             - realpath <filename>.sh
             - find ~ -name <filename>.sh
    
     - shasum machinename.vdi to get the signature
     - shasum generates a hash (SHA checksum) of the file
     - shasum -a 256 myvm.vdi > myvm_signature.txt to save it as a .txt file
     - shasum -a 256 -c myvm_signature.txt to check whether vm has been opened, corrupted or changed

  10. TMI
      
     - APT:
         - apt normally doesn't need to be downloaded as compared to aptitude
         - apt is part of the base system for debian
         - aptitude is a seperate package that uses apt underneath
      
         - apt is the installer while aptitude is just another package
         - apt and apt-get -> official, default
         - aptitude -> alternate UI + dependancy resolver
      
     - Host VS Hostname:
         - Host:
             - The host is the machine that runs the virtual machine.
             - If you’re running Debian inside VirtualBox, VMware, KVM, etc.:
                 - Your physical computer (or a cloud server) = host
                 - The Debian system running inside it = guest
             - Example:
                 - Host: your laptop running Windows/macOS/Linux
                 - Guest: Debian VM
                   
         - Hostname:
             - The hostname is simply the name of a machine on a network.
             - so for user@user42, user is the name of the user, whereas user42 is the hostname
             - It means: “this same machine”
             - It’s a special name that always points to 127.0.0.1
             - for ssh user@localhost, localhost is not the host name
                 - it is a nickname defined in /etc/hosts
                 - a well-known alias for the machine
          
         - How to change hostname:
             - sudo nano /etc/hostname
             - save and exit
             - sudo nano /etc/hosts
                 - usually see
          
                     127.0.0.1    localhost
                     127.0.1.1    old-hostname
      
                 - local name - > IP lookup table
                 - answers the question of, “If I say my own hostname, what IP address should that resolve to?”
                 - the second line means -> “My hostname resolves to a local loopback IP”
                   
             - change old-hostname to the new one
             - leave localhost alone
             - sudo reboot
          
         - Reason for needing to update /etc/hosts as well when updating hostname:
           - Many programs don’t just print the hostname — they resolve it like a network address.
           - e.g. sudo, ssh, logging services, etc.
           - If the hostname isn’t in /etc/hosts, those programs may:
               - pause for a few seconds
               - throw warnings
               - complain they “cannot resolve hostname”
           - Without /etc/hosts, Debian would try:
               - DNS (Domain Name System)
                   - like the internet's phone book
                   - DNS is the system that answers the question, “What IP address belongs to this name?”
                   - DNS allows us to use ssh user@server.example.com, instead of ssh user@203.0.113.42
                   - DNS lives outside the VM
                   - not needed if it's just for learning
               - Network
               - External name servers
           - That’s slow and unreliable — especially:
               - before networking is fully up
               - on offline VMs
               - during boot
           - IP address:
             - 127.0.0.1 is reserved for localhost
             - Debian uses 127.0.1.1 for the machine hostname
             - This avoids conflicts with services bound specifically to localhost
             ⭐ It’s a Debian convention, not universal Linux behavior.

         ✨ Extra:
             - Changing the hostname does NOT mean can SSH in from outside using that name
             - It is only for inside the VM
               - 127.x.x.x = loopback
               - Loopback addresses are not reachable from outside
               - This mapping exists only on the VM
             - Laptop does not know about the changed hostname, as laptop:
               - does not read the VM’s /etc/hosts
               - does not know about 127.0.1.1 <changed hostname>
             - So SSH fails unless:
               - DNS knows the name, or
               - your laptop has its own /etc/hosts entry
             - To have it work, either:
               - type in the IP address directly, ssh user@<IP address>
               - DNS entry, setting it up using a DNS service
               - /etc/hosts on own machine, setting it up to allow it on own laptop
     - 

Resources: 

  - born2beroot guide
  - markdown cheatsheet
  - SSH manual
