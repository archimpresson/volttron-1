#ifndef __omc_BuildingModel_h_
#define __omc_BuildingModel_h_
#include "adevs.h"
#include "adevs_public_modelica_runtime.h"

/**
 * Define the input and output type of the adevs models.
 */
#ifndef OMC_ADEVS_IO_TYPE
#define OMC_ADEVS_IO_TYPE double
#endif

/**
 * Simulation code for BuildingModel
 * generated by the OpenModelica Compiler.
 */
class BuildingModel:
    public adevs::ode_system<OMC_ADEVS_IO_TYPE>
{
    public:
       /**
        * Constructor. New state events can be added to the model by
        * passing the number of new event conditions to the constructor
        * and then extending the state_event_func method. Your state
        * events will begin at the index returned by numStateEvents().
        * You can also set the hysteresis value for the event surfaces
        * by passing a value for eventHys.
        */
       BuildingModel(int extra_state_events = 0, double eventHys = 1E-4);
       /// Destructor
       ~BuildingModel();
       /// Index of the first extra state event
       int numStateEvents() const { return numZeroCrossings(); }
       /**
        * These methods are generated by the OpenModelica compiler.
        */
       void init(double* q);
       void der_func(const double* q, double* dq);
       void postStep(double* q);
       void state_event_func(const double* q, double* z);
       /**
        * These methods may be overridden by any derived class.
        */
       virtual void extra_state_event_funcs(double* z){}
       double time_event_func(const double* q);
       void internal_event(double* q, const bool* state_event);
       void external_event(double* q, double e,
           const adevs::Bag<OMC_ADEVS_IO_TYPE>& xb){}
       void confluent_event(double *q, const bool* state_event,
           const adevs::Bag<OMC_ADEVS_IO_TYPE>& xb)
       {
           internal_event(q,state_event);
       }
       void output_func(const double *q, const bool* state_event,
           adevs::Bag<OMC_ADEVS_IO_TYPE>& yb){}
       void gc_output(adevs::Bag<OMC_ADEVS_IO_TYPE>& gb){}
       /**
        * These methods are used to access variables and
        * parameters in the modelica model by name.
        */
       double getEventEpsilon() const { return epsilon; }
       double get_time() const { return timeValue; }
       double get_t3() const { return _t3; }
       double get_t2() const { return _t2; }
       double get_t1() const { return _t1; }
       double get_energyUsed() const { return _energyUsed; }
       double get_DER_t3() const { return _DER_t3; }
       double get_DER_t2() const { return _DER_t2; }
       double get_DER_t1() const { return _DER_t1; }
       double get_DER_energyUsed() const { return _DER_energyUsed; }
       double get_solarPower() const { return _solarPower; }
       double get_d3() const { return _d3; }
       double get_d2() const { return _d2; }
       double get_d1() const { return _d1; }
       double get_dayHour() const { return _dayHour; }
       double get_dayCycle() const { return _dayCycle; }
       double get_day() const { return _day; }
       double get_C1() const { return _C1; }
       double get_C2() const { return _C2; }
       double get_C3() const { return _C3; }
       double get_K1() const { return _K1; }
       double get_K2() const { return _K2; }
       double get_K3() const { return _K3; }
       double get_K4() const { return _K4; }
       double get_K5() const { return _K5; }
       double get_solarGain() const { return _solarGain; }
       double get_heatHvac() const { return _heatHvac; }
       double get_coolHvac() const { return _coolHvac; }
       int get_coolStage() const { return _coolStage; }
       int get_heatStage() const { return _heatStage; }
       
       /// These methods are for solving non-linear algebraic eqns
       // Calculate the minimization function for initializing reals
       void initial_objective_func(double* w, double* f, double lambda);
       
    private:
       // State variables
       double _t3; double _PRE_t3;
       double _t2; double _PRE_t2;
       double _t1; double _PRE_t1;
       double _energyUsed; double _PRE_energyUsed;
       // Derivative variables
       double _DER_t3; double _PRE_DER_t3;
       double _DER_t2; double _PRE_DER_t2;
       double _DER_t1; double _PRE_DER_t1;
       double _DER_energyUsed; double _PRE_DER_energyUsed;
       // Inline variables
       // Algebraic variables
       double _solarPower; double _PRE_solarPower;
       double _d3; double _PRE_d3;
       double _d2; double _PRE_d2;
       double _d1; double _PRE_d1;
       double _dayHour; double _PRE_dayHour;
       double _dayCycle; double _PRE_dayCycle;
       double _day; double _PRE_day;
       // Integer algebraic variables
       // Boolean algebraic variables
       // Alias variables
       // Integer alias variables
       // Boolean alias variables
       // Parameter variables
       double _C1; double _PRE_C1;
       double _C2; double _PRE_C2;
       double _C3; double _PRE_C3;
       double _K1; double _PRE_K1;
       double _K2; double _PRE_K2;
       double _K3; double _PRE_K3;
       double _K4; double _PRE_K4;
       double _K5; double _PRE_K5;
       double _solarGain; double _PRE_solarGain;
       double _heatHvac; double _PRE_heatHvac;
       double _coolHvac; double _PRE_coolHvac;
       // Integer parameter variables
       int _coolStage; int _PRE_coolStage;
       int _heatStage; int _PRE_heatStage;
       // Boolean parameter variables
       // String variables
       // String parameters
       // External object variables
       // Constants
       // Integer constants
       // Boolean constants
       // String constants

       
       double epsilon;
       // These must be accessed via a pointer to localVal
       double timeValue, _PRE_timeValue;
       // Are we at an event?
       bool atEvent;
       // Are we initializing the model?
       bool atInit;
       
       // Zero crossing variables
       int *zc;
       int numZeroCrossings() const {
            return numRelations()+2*numMathEvents();
       }
       int numRelations() const { return 2; }
       int numMathEvents() const { return 1; }
       
       // Initial unknowns via solution to least squares
       void solve_for_initial_unknowns();
       std::vector<double*> init_unknown_vars;
       void bound_params();
       void save_vars();
       void restore_vars();
       void clear_event_flags();
       bool check_for_new_events();
       bool initial() const { return atInit; }
       
       void calc_vars(const double* q = NULL, bool doReinit = false);
       
       AdevsSampleData** samples;
       int numTimeEvents() const { return 0; }
       bool sample(int index, double tStart, double tInterval);
       
       AdevsDelayData** delays;
       int numDelays() const { return 0; }
       double calcDelay(int index, double expr, double t, double delay);
       void saveDelay(int index, double expr, double t, double maxdelay);
       
       AdevsMathEventFunc** eventFuncs;
       double floor(double expr, int index);
       double div(double x, double y, int index);
       int integer(double expr, int index);
       double ceil(double expr, int index);
       
       bool selectStateVars();
       
    protected:
       /**
        * Calculate the values of the state and algebraic variables.
        * State variables will be initialized to q if provided,
        * or left unchanged if not. This should be called after your
        * event handler modifies any state variables that
        * appear in the Modelica equations.
        */
       void update_vars(const double* q = NULL, bool doReinit = false)
       {
           calc_vars(q,doReinit);
           for (int i = 0; i < numMathEvents(); i++)
              if (eventFuncs[i] != NULL)
                 eventFuncs[i]->setInit(false);
           save_vars();
       }
       /**
         * These methods may be used to change paramters
         * and state variables at events. Remember to call
         * update_vars(q,true) if you change anything.
         */
       void set_t3(double val) { _t3 = val; }
       void set_t2(double val) { _t2 = val; }
       void set_t1(double val) { _t1 = val; }
       void set_energyUsed(double val) { _energyUsed = val; }
       void set_C1(double val) { _C1 = val; }
       void set_C2(double val) { _C2 = val; }
       void set_C3(double val) { _C3 = val; }
       void set_K1(double val) { _K1 = val; }
       void set_K2(double val) { _K2 = val; }
       void set_K3(double val) { _K3 = val; }
       void set_K4(double val) { _K4 = val; }
       void set_K5(double val) { _K5 = val; }
       void set_solarGain(double val) { _solarGain = val; }
       void set_heatHvac(double val) { _heatHvac = val; }
       void set_coolHvac(double val) { _coolHvac = val; }
       void set_coolStage(int val) { _coolStage = val; }
       void set_heatStage(int val) { _heatStage = val; }
 };

 #endif

