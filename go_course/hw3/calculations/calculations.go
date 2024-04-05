package calculations

import (
	"github.com/sirupsen/logrus"
)

func Calculate(n int64, log bool) int64 {
	var res int64 = 1
	if log {
		logrus.Infof("Start calculations...\nCalculate %d!\n", n);
	}
	for i := n; i > 0; i -= 1 {
		res *= i
	}
	if log {
		logrus.Info("Calculations complete!\n")
	}
	return res
}