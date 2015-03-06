Cheatsheets
===========

SSH
---

### Setting up an SSH tunnel

Suppose you have a machine at `server.com` that has a service running on port 3333, but you cannot
access that port on `server.com` due to a firewall.

You can _forward_ that port to a local port 9999 on your machine, if you can SSH into `server.com`

    ssh -f -N -L 9999:127.0.0.1:3333 user@server.com

    -f puts ssh in background
    -N makes it not execute a remote command

You can simplify this whole process with a config file.

    Host tunnel
        HostName server.com
        # this is optional, if you have a special key for server.com
        IdentityFile ~/.ssh/private.key
        LocalForward 3333 127.0.0.1:9999
        User user

