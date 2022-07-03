# 패키지 관리 도구 - apt, apitude, dpkg

[[Linux] 리눅스(Linux) 패키지 관리하기](https://gamsungcoding.tistory.com/entry/Linux-%EB%A6%AC%EB%88%85%EC%8A%A4Linux-%ED%8C%A8%ED%82%A4%EC%A7%80-%EA%B4%80%EB%A6%AC%ED%95%98%EA%B8%B0)

리눅스 배포판에 따라서 서로 다른 패키지 형식을 지원하는데 대부분 다음의 3가지 중 하나를 지원한다

1. Debian 계열 (Debian, Ubuntu 등) : `.deb` 파일
2. RedHat 계열 (RedHat, Fedora, CentOS) : `.rpm` 파일
3. openSUSE 계열 : openSUSE를 위해 특별히 빌드된 `.rpm` 파일

# apt

- Advanced Packaging Tool
- 소프트웨어의 설치와 제거를 처리하는 패키지 관리 툴이다. 초기에는 .deb 패키지를 관리하기 위해 만들었지만 현재는 rpm 패키지 매니저와도 호환
- apt는 GUI 없이 command로 사용
- 설치할 패키지 명을 입력하면, '/etc/apt/sources.list'에 지정된 소스 목록에서 해당 패키지 + 종속성 목록과 함께 찾아 자동으로 설치 (→어떤 패키지를 설치할 때 종속성 문제를 걱정하지 않아도 됨)
- 사용자가 직접 새로운 소스 목록을 추가하거나 시스템이 업그레이드 되도 해당 패키지를 업데이트 하지 않게 해 현재 버전을 계속 사용하는 등의 작업을 할 수 있다.

# apitude

- Aptitude는 사용자 인터페이스를 추가해 사용자가 대화형으로 패키지를 검색해 설치, 제거할 수 있는 high-level 패키지 관리 도구
- 데비안을 위해 만들어졌지만 rpm 기반 패키지까지 확장됨
- 텍스트 기반 대화형 인터페이스와 비대화형 command line 모드에서도 작동한다.
- 사용하지 않는 패키지는 자동적으로 제거해준다. (apt는 추가적 옵션이 필요하다. ex. `autoremove`, `-auto-remove`)
- why와 why-not 커맨드로 특정 패키지를 설치할 때 어떤 것이 요구되고, 어떤 것과 충돌하는지 확인할 수 있다.
- 설치, 제거, 업데이트 과정에서 충돌이 있는 경우 다른 대안을 제시해준다.(apt는 그냥 안된다고)

# dpkg

- low-level package manager
- dep 패키지의 삭제와 설치를 담당
- 자동으로 패키지를 다운로드하거나 종속성 문제 해결X
