# YUZA OS
YUZA OS 서적에서 설명하는 운영체제의 소스코드입니다.   

[YUZA OS Vol.1 - 소프트웨어편](http://www.acornpub.co.kr/book/yuza-os1)   
[네이버 카페](https://cafe.naver.com/codemasterproject)   

[![YUZA OS Movie](https://img.youtube.com/vi/BM-LlEVNjWU/0.jpg)](https://youtu.be/BM-LlEVNjWU) 

## Feature
* 윈도우 운영체제에서 비쥬얼 스튜디오 2019 또는 상위 버전에서 운영체제 개발
* WIN32와 실기에서 동시 동작하는 듀얼 시스템
* 강력한 선행적 디버깅 시스템 탑재
  - 커널 및 응용앱, 써드파티 라이브러리 등 모든 소스코드의 선행적 디버깅 가능
* 미니 윈도우 운영체제
* 자신만의 응용앱을 손쉽게 제작하는 방법 제시

## Build Tool
- Visual Studio 2019 또는 상위 버전
- 확장 플러그인 [VSNASM] (https://github.com/ShiftMediaProject/VSNASM)

## Build Instruction
현재 최신 개발 버전은 비쥬얼 스튜디오 2022(컴파일러 V17.0)로 변경되었습니다.
혹 비쥬얼 스튜디오 2022를 설치해서 학습하다가 문제가 발생할시에는
릴리즈탭에서 소스코드를 받아서 비쥬얼 스튜디오 2019로 진행해 주세요.
(비쥬얼 스튜디오 2022에서 2019용 컴파일러를 설치하는 것이 가능합니다. 단 이경우에는 프로젝트를 최신버전으로 업데이트하지 않아야 합니다)

* 환경변수에 YUZA_ROOT를 추가한다. 값은 YUZA OS가 설치된 경로를 입력한다.
* 프로젝트를 빌드할 시 솔루션 구성은 DEBUG, 솔루션 플랫폼은 WIN32로 설정한다.
* runtime 폴더로 이동해서 runtime.sln을 실행한 다음 빌드한다.
  정상 빌드가 되지 않는 경우 어셈블리 파일 빌드를 위해 필요한 확장 플러그인인 VSNASM이 설치됐는지 확인한다.
* corelib.sln을 실행하고 빌드한다.
* thirdparty 폴더로 이동해서 ThirdParty.sln을 실행한 다음 빌드한다.
* support.sln을 실행하고 빌드한다.
* device.sln을 실행하고 빌드한다.
* thirdParty/SDL/SDL2 폴더로 이동해서 SDL2.sln을 실행한 다음 빌드한다.
* thirdParty/SDL/SDL1CL 폴더로 이동해서 sdlcl.sln을 실행한 다음 빌드한다.
* thirdparty2 폴더로 이동해서 ThirdParty2.sln을 실행한 다음 빌드한다.
* kernel.sln 솔루션을 실행한 다음 빌드한다.

## 예제 빌드
* 프로젝트를 빌드할 시 솔루션 구성은 DEBUG, 솔루션 플랫폼은 WIN32로 설정한다.
* 챕터별 솔루션 파일을 열어서 커널을 빌드한다. 각 챕터에 따른 빌드옵션을 설정한다.
* BuildOption.h 파일을 열어서 옵션값을 변경하여 WIN32용 또는 실기용으로 빌드한다.
  * SKY_EMULATOR 1 : WIN32용 앱으로 커널 빌드
    * SKY_CONSOLE_MODE 0 : 콘솔 모드
    * SKY_CONSOLE_MODE 1 : 그래픽 모드
  * SKY_EMULATOR 0 : 가상머신용으로 커널 빌드
    * SKY_CONSOLE_MODE 0 : 콘솔 모드
    * SKY_CONSOLE_MODE 1 : 그래픽 모드

## WIN32 커널의 실행
* BIN 폴더에  image 폴더를 만든 다음 가상이미지 파일을 복사한다.
* [가상 이미지 다운로드](https://drive.google.com/drive/folders/1x2My3JrYN_EAVY4GG5o0gvbdVZLaw9wB)
* 각 챕터에 따른 가상 이미지 파일을 설정한다.
  * 예) 07_sdl_02_game.sln을 실행시 
    * yuza.cfg 파일을 연다 
    * HARDDISK 항목의 가상 이미지 이름을 07_sdl_02_game.img로 변경
* 로컬 디버거를 실행해서 디버깅을 진행한다. 

## Port List
* [ThirdParty Port List](https://docs.google.com/spreadsheets/d/1WhGbZbyi8E4f2RWTuU_Y9-RuUu7yq3mHROZEgb20GD4/edit?usp=sharing)
* [ScummVM For YUZA](https://github.com/pdpdds/scummvm4yuza)
* [DosBox For YUZA](https://github.com/pdpdds/dosbox4yuza)

## 응용앱 개발 환경 구축하기
* [기본 프로젝트 템플릿](https://github.com/pdpdds/YuzaTemplate)
* [유자 앱](https://github.com/pdpdds/YuzaApp)
* [유자 STL](https://github.com/pdpdds/yuza_stl)
* [유자 SDL](https://github.com/pdpdds/SDL_YUZA)
* [유자 써드파티](https://github.com/pdpdds/yuza_thirdparty)
* [테스트 프로젝트](https://github.com/pdpdds/yuza_test)
* 환경변수에 YUZA_ROOT를 등록. YUZA OS 루트 경로로 값을 지정
* 환경변수에 YUZA_STL를 등록. 유자 STL 루트 경로로 값을 지정
* 환경변수에 YUZA_THIRDPARTY를 등록. 유자 써드파티 루트 경로로 값을 지정




