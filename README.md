CSM
===

2013년 3학기 게임개발경험프로젝트 치킨정식팀 (Chicken set meal : 장문익, 이선협, 김지환, 남세현)

Demo Video
----------
[Youtube Link](https://www.youtube.com/watch?v=CjgzqgIMD6I&t=6s)

How to Play
-----------
1. http://125.209.199.224/ 에 접속합니다.
2. 회원가입 후 로그인합니다.
3. 재밌게 플레이하세요~

How to build
------------

1. 이 저장소를 로컬에 클론합니다. `git clone https://github.com/jihwankim/CSM.git`
2. 클론된 폴더로 이동한 뒤 등록되어 있는 서브모듈인 NNGameFramework를 불러옵니다. `git submodule init`
3. 서브모듈을 업데이트 해줍니다. `git submodule update`
4. 생성된 서브모듈 저장소는 headress 상태 입니다. 해당 저장소로 이동한 뒤 `git checkout master`를 입력해주세요.
5. 마지막으로 가장 최신 상태로 유지하기 위해 `git pull origin master`를 입력해주세요.
6. CSMGameProject 프로젝트를 Visual studio 2012로 연 후 컴파일한 후 실행하면 됩니다.

* 로비가 되는 웹서버는 `src/CSMWebServer`의 문서를 참고해주세요.

Thrid Party
-----------

1. NNGameFramework (https://github.com/kciter/NNGameFramework)
2. EasyGameServer (https://github.com/zeliard/EasyGameServer)
3. Direct3D
4. Direct2D
5. FMOD
6. TinyXML
7. sqlite3
8. zip utils
9. md5

Contributing to the Project
---------------------------

* 김지환
* 이선협
* 장문익
* 남세현

License
-------
The MIT License (MIT)

Copyright (c) 2013 CSM
