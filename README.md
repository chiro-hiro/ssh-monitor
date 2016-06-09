# SSH monitor

## Introduction
Some time you need to give someone ability to make change to your system. And the question is how to record all SSH session to file ?. 
It is possible with **SSH monitor** a modified version of **openSSH**.

## Installation

### Clone source code

Open Terminal and make sure that you got git.
``` bash
$ git clone https://github.com/tad88dev/ssh-monitor.git
```
Configure and make from source.
``` bash
$ cd ssh-monitor
$ ./configure
$ make
ROOT> mkdir /var/log/ssh-monitor
ROOT> chmod 777 /var/log/ssh-monitor
ROOT> cp -f ./ssh `which ssh`
```

### Testing
Connect to SSH server and try to type some command.
``` bash
$ ssh root@192.168.1.221
```
Result:
``` bash
[chiro@localhost ssh-monitor]$ cat /var/log/ssh-monitor/192.168.1.221-159-6-2016.log
�Last login: Wed Jun  8 05:18:42 2016 from 192.168.1.56
[root@localhost ~]# ps -A
  PID TTY          TIME CMD
    1 ?        00:00:23 systemd
    2 ?        00:00:00 kthreadd
    3 ?        00:00:06 ksoftirqd/0
    7 ?        00:00:00 migration/0
    8 ?        00:00:00 rcu_bh
    9 ?        00:00:00 rcuob/0
   10 ?        00:00:00 rcuob/1
   11 ?        00:02:35 rcu_sched
   12 ?        00:02:14 rcuos/0
   13 ?        00:02:06 rcuos/1
   14 ?        00:00:08 watchdog/0
   15 ?        00:00:06 watchdog/1
   16 ?        00:00:00 migration/1
   17 ?        00:00:06 ksoftirqd/1
   19 ?        00:00:00 kworker/1:0H
   20 ?        00:00:00 khelper
   21 ?        00:00:00 kdevtmpfs
   22 ?        00:00:00 netns
   23 ?        00:00:00 perf
   24 ?        00:00:00 writeback
   25 ?        00:00:00 kintegrityd
   26 ?        00:00:00 bioset
   27 ?        00:00:00 kblockd
   28 ?        00:00:00 md
   33 ?        00:00:00 khungtaskd
   34 ?        00:09:29 kswapd0
   35 ?        00:00:00 ksmd
   36 ?        00:00:08 khugepaged
   37 ?        00:00:00 fsnotify_mark
   38 ?        00:00:00 crypto
   46 ?        00:00:00 kthrotld
   48 ?        00:00:00 kmpath_rdacd
   50 ?        00:00:00 kpsmoused
   51 ?        00:00:00 ipv6_addrconf
   71 ?        00:00:00 deferwq
  102 ?        00:00:00 kauditd
  232 ?        00:00:00 ata_sff
  233 ?        00:00:00 scsi_eh_0
  234 ?        00:00:00 events_power_ef
  237 ?        00:00:00 scsi_tmf_0
  240 ?        00:00:00 scsi_eh_1
  243 ?        00:00:00 scsi_tmf_1
  246 ?        00:00:00 mpt_poll_0
  248 ?        00:00:00 mpt/0
  258 ?        00:00:00 scsi_eh_2
  259 ?        00:00:00 scsi_tmf_2
  261 ?        00:00:00 ttm_swap
  272 ?        00:00:31 kworker/1:1H
  283 ?        00:00:00 jbd2/sda3-8
  284 ?        00:00:00 ext4-rsv-conver
  285 ?        00:00:00 ext4-unrsv-conv
  355 ?        00:00:09 systemd-journal
  378 ?        00:00:00 systemd-udevd
  434 ?        00:00:00 xfsalloc
  435 ?        00:00:00 xfs_mru_cache
  436 ?        00:00:00 xfs-buf/sda5
  437 ?        00:00:00 xfs-data/sda5
  438 ?        00:00:00 xfs-conv/sda5
  439 ?        00:00:00 xfs-cil/sda5
  440 ?        00:01:39 xfsaild/sda5
  444 ?        00:00:00 jbd2/sda2-8
  445 ?        00:00:00 ext4-rsv-conver
  446 ?        00:00:00 ext4-unrsv-conv
  462 ?        00:00:01 auditd
  485 ?        00:00:00 rsyslogd
  486 ?        00:00:08 systemd-logind
  487 ?        00:00:59 irqbalance
  488 ?        00:00:03 dbus-daemon
  494 ?        00:00:05 NetworkManager
  499 ?        00:00:03 crond
  501 tty1     00:00:00 agetty
  510 ?        00:00:00 wpa_supplicant
  511 ?        00:00:00 polkitd
  760 ?        00:00:00 sshd
  762 ?        00:03:01 tuned
 1552 ?        00:00:06 master
 1572 ?        00:00:01 qmgr
 2465 ?        00:00:00 kworker/0:0H
 9707 ?        02:33:04 bitcore
 9759 ?        00:00:00 kworker/0:1H
 9821 ?        00:00:03 kworker/0:0
 9938 ?        00:00:00 kworker/u4:2
10190 ?        00:00:00 kworker/u4:1
10829 ?        00:00:00 kworker/1:1
11149 ?        00:00:00 kworker/1:2
11176 ?        00:00:00 pickup
11250 ?        00:00:00 kworker/0:2
11251 ?        00:00:00 kworker/0:1
11252 ?        00:00:00 sshd
11256 pts/1    00:00:00 bash
11271 pts/1    00:00:00 ps
[root@localhost ~]# ls -la
total 48
dr-xr-x---.  3 root root 4096 May 26 05:40 .
dr-xr-xr-x. 18 root root 4096 May 21 08:26 ..
-rw-------.  1 root root 4940 Jun  8 05:18 .bash_history
-rw-r--r--.  1 root root   18 Dec 28  2013 .bash_logout
-rw-r--r--.  1 root root  176 Dec 28  2013 .bash_profile
-rw-r--r--.  1 root root  176 Dec 28  2013 .bashrc
-rw-r--r--.  1 root root  100 Dec 28  2013 .cshrc
-rw-r--r--.  1 root root  386 May 21 09:12 ifcfg-ens160
-rw-r--r--.  1 root root  129 Dec 28  2013 .tcshrc
[root@localhost ~]# du -h /etc
4.0K	/etc/pkcs11/modules
8.0K	/etc/pkcs11
76K	/etc/bash_completion.d
4.0K	/etc/dnsmasq.d
68K	/etc/openldap/certs
76K	/etc/openldap
4.0K	/etc/systemd/user
4.0K	/etc/systemd/system/getty.target.wants
4.0K	/etc/systemd/system/system-update.target.wants
4.0K	/etc/systemd/system/default.target.wants
4.0K	/etc/systemd/system/basic.target.wants
4.0K	/etc/systemd/system/multi-user.target.wants
24K	/etc/systemd/system
56K	/etc/systemd
12K	/etc/libnl
16K	/etc/prelink.conf.d
4.0K	/etc/rwtab.d
128K	/etc/pki/nssdb
4.0K	/etc/pki/ca-trust/source/anchors
4.0K	/etc/pki/ca-trust/source/blacklist
16K	/etc/pki/ca-trust/source
676K	/etc/pki/ca-trust/extracted/pem
348K	/etc/pki/ca-trust/extracted/openssl
200K	/etc/pki/ca-trust/extracted/java
1.3M	/etc/pki/ca-trust/extracted
1.3M	/etc/pki/ca-trust
4.0K	/etc/pki/rsyslog
4.0K	/etc/pki/CA/private
4.0K	/etc/pki/CA/newcerts
4.0K	/etc/pki/CA/certs
4.0K	/etc/pki/CA/crl
20K	/etc/pki/CA
4.0K	/etc/pki/tls/private
16K	/etc/pki/tls/certs
28K	/etc/pki/tls/misc
64K	/etc/pki/tls
16K	/etc/pki/rpm-gpg
4.0K	/etc/pki/java
1.5M	/etc/pki
4.0K	/etc/chkconfig.d
8.0K	/etc/plymouth
44K	/etc/rpm
4.0K	/etc/gcrypt
4.0K	/etc/X11/fontpath.d
4.0K	/etc/X11/applnk
8.0K	/etc/X11/xorg.conf.d
20K	/etc/X11
8.0K	/etc/depmod.d
4.0K	/etc/opt
8.0K	/etc/audit/rules.d
24K	/etc/audit
12K	/etc/audisp/plugins.d
20K	/etc/audisp
8.0K	/etc/wpa_supplicant
4.0K	/etc/NetworkManager/dnsmasq.d
4.0K	/etc/NetworkManager/system-connections
8.0K	/etc/NetworkManager/conf.d
4.0K	/etc/NetworkManager/dispatcher.d/pre-up.d
4.0K	/etc/NetworkManager/dispatcher.d/pre-down.d
20K	/etc/NetworkManager/dispatcher.d
4.0K	/etc/NetworkManager/VPN
48K	/etc/NetworkManager
4.0K	/etc/pm/power.d
4.0K	/etc/pm/sleep.d
4.0K	/etc/pm/config.d
16K	/etc/pm
8.0K	/etc/yum/protected.d
8.0K	/etc/yum/vars
12K	/etc/yum/pluginconf.d
4.0K	/etc/yum/fssnap.d
48K	/etc/yum
4.0K	/etc/statetab.d
4.0K	/etc/polkit-1/localauthority.conf.d
4.0K	/etc/polkit-1/localauthority/10-vendor.d
4.0K	/etc/polkit-1/localauthority/50-local.d
4.0K	/etc/polkit-1/localauthority/90-mandatory.d
4.0K	/etc/polkit-1/localauthority/20-org.d
4.0K	/etc/polkit-1/localauthority/30-site.d
24K	/etc/polkit-1/localauthority
12K	/etc/polkit-1/rules.d
44K	/etc/polkit-1
16K	/etc/default
76K	/etc/grub.d
32K	/etc/yum.repos.d
4.0K	/etc/binfmt.d
4.0K	/etc/xinetd.d
4.0K	/etc/xdg/systemd
4.0K	/etc/xdg/autostart
12K	/etc/xdg
4.0K	/etc/dracut.conf.d
4.0K	/etc/ssl
16K	/etc/skel
4.0K	/etc/ppp/peers
56K	/etc/ppp
4.0K	/etc/sysctl.d
8.0K	/etc/python
4.0K	/etc/security/console.perms.d
4.0K	/etc/security/namespace.d
8.0K	/etc/security/limits.d
4.0K	/etc/security/console.apps
76K	/etc/security
4.0K	/etc/gss/mech.d
8.0K	/etc/gss
104K	/etc/pam.d
4.0K	/etc/modprobe.d
12K	/etc/cron.hourly
4.0K	/etc/gdbinit.d
8.0K	/etc/tmpfiles.d
4.0K	/etc/rc.d/rc5.d
36K	/etc/rc.d/init.d
4.0K	/etc/rc.d/rc3.d
4.0K	/etc/rc.d/rc0.d
4.0K	/etc/rc.d/rc6.d
4.0K	/etc/rc.d/rc4.d
4.0K	/etc/rc.d/rc2.d
4.0K	/etc/rc.d/rc1.d
72K	/etc/rc.d
4.0K	/etc/terminfo
4.0K	/etc/modules-load.d
4.0K	/etc/udev/rules.d
6.7M	/etc/udev
4.0K	/etc/sysconfig/modules
4.0K	/etc/sysconfig/console
12K	/etc/sysconfig/cbq
200K	/etc/sysconfig/network-scripts
300K	/etc/sysconfig
8.0K	/etc/my.cnf.d
4.0K	/etc/subversion
4.0K	/etc/popt.d
4.0K	/etc/alternatives
16K	/etc/cron.daily
4.0K	/etc/gnupg
8.0K	/etc/cron.d
8.0K	/etc/rsyslog.d
20K	/etc/ld.so.conf.d
4.8M	/etc/selinux/targeted/modules/active/modules
5.6M	/etc/selinux/targeted/modules/active
5.6M	/etc/selinux/targeted/modules
4.0K	/etc/selinux/targeted/logins
3.7M	/etc/selinux/targeted/policy
1.7M	/etc/selinux/targeted/contexts/files
32K	/etc/selinux/targeted/contexts/users
1.8M	/etc/selinux/targeted/contexts
11M	/etc/selinux/targeted
11M	/etc/selinux
8.0K	/etc/sasl2
32K	/etc/iproute2
24K	/etc/logrotate.d
280K	/etc/ssh
16K	/etc/tuned
52K	/etc/profile.d
4.0K	/etc/dhcp/dhclient.d
8.0K	/etc/dhcp
8.0K	/etc/avahi
4.0K	/etc/cron.monthly
4.0K	/etc/dbus-1/session.d
84K	/etc/dbus-1/system.d
100K	/etc/dbus-1
4.0K	/etc/cron.weekly
152K	/etc/postfix
4.0K	/etc/sudoers.d
12K	/etc/groff/site-tmac
4.0K	/etc/groff/site-font
20K	/etc/groff
8.0K	/etc/kernel/postinst.d
12K	/etc/kernel
23M	/etc
[root@localhost ~]# exitexit-statuseow@openssh.com
logout
[chiro@localhost ssh-monitor]$ 
```

