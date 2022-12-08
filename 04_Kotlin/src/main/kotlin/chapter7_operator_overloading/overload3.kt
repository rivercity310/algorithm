package chapter7_operator_overloading

// [ 프로퍼티 접근자 로직 재활용: 위임 프로퍼티 ]
// - 위임 프로퍼티를 사용하면 값을 뒷받침하는 필드에 단순히 저장하는 것보다 더 복잡한 방식으로 작동하는 프로퍼티를 쉽게 구현할 수 있다.
// ex) 프로퍼티는 위임을 사용해 자신의 값을 필드가 아닌 DB 테이블이나 브라우저 세션, 맵 등에 저장할 수 있다.

// 위임: 객체가 직접 작업을 수행하지 않고 다른 도우미 객체(위임 객체)가 그 작업을 처리하게 맡기는 디자인 패턴


// 위임 프로퍼티
class Foo {
}