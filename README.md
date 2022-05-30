# Supply chain security demo
A traditional software CI/CD pipeline which builds software and then ships it to a content delivery network.
Can be used to demonstrate breaches of security in the content delivery network by copying an evil RPM in a local repo or in the development process by switching the pipeline to use EvilPipeline instead of Jenkinsfile.

## Build environment
* A Jenkins server running on RHEL 8.
* A Jenkins RHEL 8 slave which signs RPMs with a secret GPG key, see: https://access.redhat.com/articles/3359321

## Content delivery network
A normal yum repo server which has a script to synchronize RPMs found in this git repo to the yum repository. Synchronization is done by running a script such as this:
```
#!/usr/bin/bash

rm -rf companyapp
git clone https://github.com/RedHatNordicsSA/companyapp
cp companyapp/RPMS/x86_64/* /var/www/html/repo/
createrepo -v /var/www/html/repo
```

