#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define eps 1e-8
#define zero(x) (fabs(x)<eps?1:0)

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int D;
	// 速度：度/秒
	const double vs = 360.0 / 60;
	const double vm = 360.0 / (60 * 60);
	const double vh = 360.0 / (12 * 60 * 60);
	// 重合周期：秒
	const double tsm = 360.0 / fabs(vs - vm);
	const double tmh = 360.0 / fabs(vm - vh);
	const double ths = 360.0 / fabs(vh - vs);
	// 总时间
	const double T = 43200;
	// Solve
	while (scanf("%d", &D) && D != -1) {
		// 开始时间
		double ssm = D / 360.0 * tsm;
		double smh = D / 360.0 * tmh;
		double shs = D / 360.0 * ths;
		// 结束时间
		double esm = (360 - D) / 360.0 * tsm;
		double emh = (360 - D) / 360.0 * tmh;
		double ehs = (360 - D) / 360.0 * ths;
		// 总happy时间
		double ans = 0;
		// happy区间
		double sh = max(ssm, max(smh, shs));
		double eh = min(esm, min(emh, ehs));
		// 统计
		while (ssm + D / 360.0 * tmh < T && smh + D / 360.0 * tmh < T && shs + D / 360.0 * tmh < T) {
			// happy区间
			sh = max(ssm, max(smh, shs));
			eh = min(esm, min(emh, ehs));
			// 累加
			ans += max(0.0, eh - sh);
			// 更新区间
			if (zero(eh - esm)) {
				ssm += tsm;
				esm += tsm;
			}
			// 更新区间
			if (zero(eh - emh)) {
				smh += tmh;
				emh += tmh;
			}
			// 更新区间
			if (zero(eh - ehs)) {
				shs += ths;
				ehs += ths;
			}
		}
		// 输出
		printf("%.3f\n", ans / 432.0);
	}
	return 0;
}
