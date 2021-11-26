#ifndef SIMULATOR_H
#define SIMULATOR_H

template <typename Sim_t, typename Trace_t>
class Simulator : public ::testing::Test {
protected:
	Simulator(void) {
		sim = new Sim_t();
		tfp = new Trace_t();
	}
	virtual ~Simulator(void) {
		delete sim;
		delete tfp;
	}
	virtual void SetUp(const char *filename) {
		sim->trace(tfp, 99);
		tfp->open(filename);

		m_clock_count = 0;
		Reset();
	}
	virtual void TearDown(void) {
		tfp->close();
	}
	virtual void Eval(void) {
		sim->eval();
	}
	void UpdatePorts(void) {
		Eval();
	}
	virtual uint64_t Tick(void) {
		sim->p_reset = p_reset;
		sim->m_clock = m_clock;
		m_clock = !m_clock;
		sim->eval();
		tfp->dump(m_clock_count);
		m_clock_count++;
		sim->p_reset = p_reset;
		sim->m_clock = m_clock;
		m_clock = !m_clock;
		sim->eval();
		tfp->dump(m_clock_count);
		m_clock_count++;

		return m_clock_count;
	}
	virtual void Reset(void) {
		p_reset = true;
		m_clock = true;
		Tick();
		p_reset = false;
	}
	virtual void Autorun(uint64_t count) {
		for(uint64_t i = 0; i < count; i++) {
			Tick();
		}
	}
	uint64_t m_clock_count;
	Trace_t *tfp;
	bool m_clock;
	bool p_reset;
public:
	Sim_t *sim;
};

#endif
