--TEST--
PDO Common: PDO::FETCH_UNIQUE
--SKIPIF--
<?php # vim:ft=php
if (!extension_loaded('pdo')) die('skip');
$dir = getenv('REDIR_TEST_DIR');
//if (false == $dir) die('skip no driver');
require_once $dir . 'pdo_test.inc';
PDOTest::skip();
?>
--FILE--
<?php
if (getenv('REDIR_TEST_DIR') === false) putenv('REDIR_TEST_DIR='.dirname(__FILE__) . '/../../pdo/tests/');
require_once getenv('REDIR_TEST_DIR') . 'pdo_test.inc';
$db = PDOTest::factory();

		try {
$db->exec('CREATE TABLE test(id varCHAR(1) NOT NULL, val VARCHAR(10))');
		} catch (PDOException $e) {
			die("skip " . $e->getMessage());
		}
$db->exec("INSERT INTO test VALUES('A', 'A')");
$db->exec("INSERT INTO test VALUES('B', 'A')");
$db->exec("INSERT INTO test VALUES('C', 'C')");

$stmt = $db->prepare('SELECT id, val from test');

$stmt->execute();
var_dump($stmt->fetchAll(PDO::FETCH_NUM|PDO::FETCH_UNIQUE));

$stmt->execute();
var_dump($stmt->fetchAll(PDO::FETCH_ASSOC|PDO::FETCH_UNIQUE));

?>
--EXPECT--
array(3) {
  ["A"]=>
  array(1) {
    [0]=>
    string(1) "A"
  }
  ["B"]=>
  array(1) {
    [0]=>
    string(1) "A"
  }
  ["C"]=>
  array(1) {
    [0]=>
    string(1) "C"
  }
}
array(3) {
  ["A"]=>
  array(1) {
    ["val"]=>
    string(1) "A"
  }
  ["B"]=>
  array(1) {
    ["val"]=>
    string(1) "A"
  }
  ["C"]=>
  array(1) {
    ["val"]=>
    string(1) "C"
  }
}
