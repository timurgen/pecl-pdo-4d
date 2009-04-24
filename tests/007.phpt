--TEST--
PDO_4D: Comptage de nombres de colonnes
--FILE--
<?php
require dirname(__FILE__) . '/../../../ext/pdo/tests/pdo_test.inc';
$db = PDOTest::test_factory(dirname(__FILE__) . '/common.phpt');

$db->query("CREATE TABLE test ( a VARCHAR, b VARCHAR, c VARCHAR )");
$db->query("INSERT INTO test VALUES ( 'a1','b1','c1')");
$db->query("INSERT INTO test VALUES ( 'a','b','c')");
$db->query("INSERT INTO test VALUES ( 'a2','b2','c2')");

$r = $db->query("SELECT * FROM test");
var_dump($r->columnCount());


?>
--EXPECTF--
int(3)
