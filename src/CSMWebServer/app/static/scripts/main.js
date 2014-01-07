
$(document).ready(function() {
	$('#login').click(function() {
		$('.loginModal').show();
	});
	$('#regist').click(function() {
		$('.registModal').show();
	});
	$('#info').click(function() {
		$('.userInfoModal').show();
	});
	$('#logout').click(function() {
		location.href = '/user/logout';
	});

	$('.formLogin').submit(function() {
		if ( this.email.value == '' ) {
			alert( '이메일을 입력해주세요.' );
			return false;
		} else if ( this.password.value == '' ) {
			alert( '비밀번호를 입력해주세요.' );
			return false;
		}

		return true;
	});

	$('.formRegist').submit(function() {
		if ( this.email.value == '' ) {
			alert( '이메일을 입력해주세요.' );
			return false;
		} else if ( this.password.value == '' ) {
			alert( '비밀번호를 입력해주세요.' );
			return false;
		} else if ( this.confirm.value == '' ) {
			alert( '비밀번호 확인을 입력해주세요.' );
			return false;
		} else if ( this.nickname.value == '' ) {
			alert( '닉네임을 입력해주세요.' );
			return false;
		} else if ( this.password.value != this.confirm.value ) {
			alert( '비밀번호가 다릅니다. 확인햏주세요.' );
			return false;
		}

		return true;
	});

	$('.exit').click(function() {
		$(this).parent().parent().hide();
	});
});

$(window).load(function() {
});
