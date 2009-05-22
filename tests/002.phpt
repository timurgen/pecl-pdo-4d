--TEST--
PDO_4D: Testing table creation
--SKIPIF--
<?php # vim:ft=php
if (!extension_loaded('pdo')) die('skip');
if (!interface_exists('Serializable')) die('skip no Serializable interface');
$dir = getenv('REDIR_TEST_DIR');
//if (false == $dir) die('skip no driver');
require_once $dir . 'pdo_test.inc';
PDOTest::skip();
?>
--FILE--
<?php
require dirname(__FILE__) . '/../../../ext/pdo/tests/pdo_test.inc';
$db = PDOTest::test_factory(dirname(__FILE__) . '/common.phpt');

$db->query('CREATE TABLE IF NOT EXISTS foobar ( c TEXT )');

$r = $db->query('SELECT * FROM foobar');
var_dump($r->rowCount());

$db->query('DROP TABLE foobar');
?>
--EXPECTF--
int(0)
