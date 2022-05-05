pipeline {

  agent {
    label 'rhel8slave'
  }

  stages {

    stage ('Get latest source code') {
      steps {
        sh '''
          if [ -d companyapp ]
          then
            rm -rf companyapp
          fi
          git clone git@github.com:mglantz/companyapp
        '''
      }
    }

    stage ('Setup build environment') {
      steps {
        sh '''
          dnf install -y make rpm-sign pinentry gnupg2
        '''
      }
    }

    stage ('Validate build environment') {
      steps {
        sh '''
          rpm --version
          gpg --version
          make --version
        '''
      }
    }
    
  stage ('Validate source code and .spec signatures') {
      steps {
        sh '''
          cd companyapp
          if [ -f app.spec ]
          then
            CHECKSUM="75097cfa1c456fbd2ab8919323e09b0a387a8beb19a74080cadb415fe9374d2e"
            CHECKEDSUM=$(sha256sum src/app.c|awk '{ print $1 }')
            if echo $CHECKSUM|grep -q $CHECKEDSUM
            then
              echo "Source code signature matches."
            else
              echo "Alert: source code signature does not match"
              exit 1
            fi
          fi
          if [ -f app.spec ]
          then
            CHECKSUM="67decbb7b4f4822ed8c29a31aa69d91cca2e84a63d87a71de3d4344060a675b2"
            CHECKEDSUM=$(sha256sum app.spec|awk '{ print $1 }')
            if echo $CHECKSUM|grep -q $CHECKEDSUM
            then
              echo "Spec file signature matches."
            else
              echo "Alert: spec file signature does not match"
              exit 1
            fi
          fi
        '''
      }
    }  

    stage ('Compile source') {
      steps {
        sh '''
          cd companyapp
          make
        '''
      }
    }
    
    stage ('Test') {
      steps {
        sh '''
          cd companyapp
          chmod a+rx ./app
          ./app
        '''
      }
    }

    stage ('Build RPM') {
      steps {
        sh '''
          cd companyapp
          rpmbuild -ba ./app.spec
        '''
      }
    }
  
    stage ('Sign RPMs') {
      steps {
        sh '''
          cd companyapp
          RPMS=$(find /root/workspace/company-build-pipeline/companyapp/RPMS/x86_64 -type f)
          for RPM in ${RPMS[@]}
          do
            rpm --addsign $RPM
          done
        '''
      }
    }
  
    stage ('Upload signed RPMs to github') {
      steps {
        sh '''
          cd companyapp
          RPMS=$(find /root/workspace/company-build-pipeline/companyapp/RPMS/x86_64 -type f)
          for RPM in ${RPMS[@]}
          do
            rpm --checksig $RPM
            if [ "$?" -eq 0 ]
            then
                git add $RPM
            fi
          done
          git commit -m 'New RPM release'
          git push
        '''
      }
    }
  }
}
