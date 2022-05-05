Name:       companyapp
Version:    1
Release:    1
Summary:    The company app
License:    GPL 3.0

%description
The company app. Very important and popular software.

%prep
# None

%build
# None

%install
mkdir -p %{buildroot}/usr/bin/
install -m 755 /root/workspace/company-build-pipeline/companyapp/app %{buildroot}/usr/bin/app

%files
/usr/bin/app

%changelog
# None
